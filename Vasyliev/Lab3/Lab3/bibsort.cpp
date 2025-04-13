#include <iostream>
#include <fstream>
#include <cstring>
#include <iconv.h>
#include <errno.h>

using namespace std;

// Функция для определения кодировки файла (упрощенная версия)
string detectFileEncoding(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) return "unknown";

    // Проверка BOM (Byte Order Mark) для UTF-8
    char bom[3];
    file.read(bom, 3);
    if (file.gcount() >= 3 &&
        (unsigned char)bom[0] == 0xEF &&
        (unsigned char)bom[1] == 0xBB &&
        (unsigned char)bom[2] == 0xBF) {
        return "UTF-8";
    }
    file.seekg(0);

    // Статистический анализ (примитивный)
    int highBytes = 0;
    int totalBytes = 0;
    char ch;
    while (file.get(ch)) {
        if ((unsigned char)ch > 0x7F) highBytes++;
        totalBytes++;
        if (totalBytes > 1000) break; // Проверяем только начало файла
    }

    // Если много символов > 0x7F - вероятно Windows-1251
    if (totalBytes > 0 && (highBytes * 100 / totalBytes) > 10) {
        return "WINDOWS-1251";
    }

    return "ASCII/UTF-8"; // По умолчанию
}

// Улучшенная функция конвертации с выводом ошибок
string convertEncodingWithDiagnostics(const string& input, const char* from, const char* to, const string& filename) {
    iconv_t cd = iconv_open(to, from);
    if (cd == (iconv_t)-1) {
        cerr << "ОШИБКА ICONV_OPEN: Невозможно конвертировать из " << from
            << " в " << to << " (файл: " << filename << ")" << endl;
        return input;
    }

    size_t inbytes = input.size();
    size_t outbytes = inbytes * 4; // Запас для UTF-8
    char* inbuf = const_cast<char*>(input.c_str());
    char* outbuf = new char[outbytes];
    char* outptr = outbuf;

    if (iconv(cd, &inbuf, &inbytes, &outptr, &outbytes) == (size_t)-1) {
        cerr << "ОШИБКА ICONV: ";
        switch (errno) {
        case EILSEQ:
            cerr << "Некорректная последовательность байт во входных данных";
            break;
        case E2BIG:
            cerr << "Недостаточно места в выходном буфере";
            break;
        case EINVAL:
            cerr << "Неполная последовательность байт на входе";
            break;
        default:
            cerr << "Неизвестная ошибка";
        }
        cerr << " (файл: " << filename << ", кодировка: " << from << ")" << endl;

        // Вывод проблемных символов (первые 16 байт)
        cerr << "Проблемные данные (hex):";
        for (size_t i = 0; i < min(input.size(), (size_t)16); ++i) {
            cerr << " " << hex << (unsigned int)(unsigned char)input[i];
        }
        cerr << dec << endl;

        iconv_close(cd);
        delete[] outbuf;
        return input;
    }

    string result(outbuf, outptr - outbuf);
    iconv_close(cd);
    delete[] outbuf;
    return result;
}

// Пример использования в функции parseBibFile
BibRecord parseBibFile(const string& filename) {
    BibRecord record;
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "ОШИБКА: Не удалось открыть файл " << filename << endl;
        return record;
    }

    // Определяем кодировку файла
    string fileEncoding = detectFileEncoding(filename);
    cout << "Обработка файла: " << filename << " (кодировка: " << fileEncoding << ")" << endl;

    string line;
    while (getline(file, line)) {
        // Конвертируем в UTF-8 перед парсингом
        string convertedLine;
        if (fileEncoding != "UTF-8") {
            convertedLine = convertEncodingWithDiagnostics(line, fileEncoding.c_str(), "UTF-8", filename);
        }
        else {
            convertedLine = line;
        }

        // ... далее ваш парсинг ...
    }

    return record;
}