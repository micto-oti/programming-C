#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <dirent.h>
#include <cstring>
#include <iconv.h>

using namespace std;

// Структура для хранения библиографической записи
struct BibEntry {
    string author;
    string title;
    string year;
    string publisher;
    string full_entry;
};

// Функция для сравнения русских строк по первым 5 символам (аналог strncmp для cp1251)
int strncmp_cp1251(const char* s1, const char* s2, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        if (s1[i] != s2[i]) {
            return (unsigned char)s1[i] - (unsigned char)s2[i];
        }
        if (s1[i] == '\0') {
            return 0;
        }
    }
    return 0;
}

// Функция для конвертации кодировки (например, UTF-8 в CP1251)
string convert_encoding(const string& input, const char* from_encoding, const char* to_encoding) {
    iconv_t cd = iconv_open(to_encoding, from_encoding);
    if (cd == (iconv_t)-1) {
        cerr << "Ошибка открытия iconv" << endl;
        return input;
    }

    size_t in_bytes = input.size();
    size_t out_bytes = in_bytes * 2;
    char* in_buf = const_cast<char*>(input.data());
    char* out_buf = new char[out_bytes];
    char* out_ptr = out_buf;

    if (iconv(cd, &in_buf, &in_bytes, &out_ptr, &out_bytes) == (size_t)-1) {
        cerr << "Ошибка конвертации iconv" << endl;
        iconv_close(cd);
        delete[] out_buf;
        return input;
    }

    string result(out_buf, out_ptr - out_buf);
    iconv_close(cd);
    delete[] out_buf;
    return result;
}

// Функция для извлечения значения из поля .bib записи
string extract_field(const string& entry, const string& field_name) {
    size_t start = entry.find(field_name + " = {");
    if (start == string::npos) return "";

    start += field_name.length() + 4;
    size_t end = entry.find("}", start);
    if (end == string::npos) return "";

    return entry.substr(start, end - start);
}

// Функция для обработки одного .bib файла
void process_bib_file(const string& filename, vector<BibEntry>& entries) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Не удалось открыть файл: " << filename << endl;
        return;
    }

    string line;
    string current_entry;
    bool in_entry = false;

    while (getline(file, line)) {
        if (line.find("@") == 0) {
            if (!current_entry.empty()) {
                BibEntry entry;
                entry.full_entry = current_entry;
                entry.author = extract_field(current_entry, "author");
                entry.title = extract_field(current_entry, "title");
                entry.year = extract_field(current_entry, "year");
                entry.publisher = extract_field(current_entry, "publisher");

                // Конвертируем в CP1251 для корректного сравнения
                entry.author = convert_encoding(entry.author, "UTF-8", "CP1251");
                entry.title = convert_encoding(entry.title, "UTF-8", "CP1251");

                entries.push_back(entry);
            }
            current_entry = line + "\n";
            in_entry = true;
        }
        else if (in_entry) {
            current_entry += line + "\n";
        }
    }

    // Добавляем последнюю запись
    if (!current_entry.empty()) {
        BibEntry entry;
        entry.full_entry = current_entry;
        entry.author = extract_field(current_entry, "author");
        entry.title = extract_field(current_entry, "title");
        entry.year = extract_field(current_entry, "year");
        entry.publisher = extract_field(current_entry, "publisher");

        entry.author = convert_encoding(entry.author, "UTF-8", "CP1251");
        entry.title = convert_encoding(entry.title, "UTF-8", "CP1251");

        entries.push_back(entry);
    }

    file.close();
}

// Функция для поиска всех .bib файлов в директории
vector<string> find_bib_files(const string& directory) {
    vector<string> bib_files;
    DIR* dir;
    struct dirent* ent;

    if ((dir = opendir(directory.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            string filename = ent->d_name;
            if (filename.size() > 4 && filename.substr(filename.size() - 4) == ".bib") {
                bib_files.push_back(directory + "/" + filename);
            }
        }
        closedir(dir);
    }
    else {
        cerr << "Не удалось открыть директорию: " << directory << endl;
    }

    return bib_files;
}

// Компаратор для сортировки записей
bool compare_entries(const BibEntry& a, const BibEntry& b) {
    // Сравниваем по первым 5 символам автора
    int author_cmp = strncmp_cp1251(a.author.c_str(), b.author.c_str(), 5);
    if (author_cmp != 0) return author_cmp < 0;

    // Если авторы совпадают, сравниваем по названиям
    return strncmp_cp1251(a.title.c_str(), b.title.c_str(), 5) < 0;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Использование: " << argv[0] << " <выходной файл> <папка1> [папка2] ..." << endl;
        return 1;
    }

    string output_file = argv[1];
    vector<string> directories;
    for (int i = 2; i < argc; ++i) {
        directories.push_back(argv[i]);
    }

    vector<BibEntry> all_entries;

    // Обрабатываем все указанные директории
    for (const auto& dir : directories) {
        vector<string> bib_files = find_bib_files(dir);
        for (const auto& file : bib_files) {
            process_bib_file(file, all_entries);
        }
    }

    // Сортируем записи
    sort(all_entries.begin(), all_entries.end(), compare_entries);

    // Записываем результат в выходной файл
    ofstream out(output_file);
    if (!out.is_open()) {
        cerr << "Не удалось открыть выходной файл: " << output_file << endl;
        return 1;
    }

    for (const auto& entry : all_entries) {
        // Конвертируем обратно в UTF-8 для вывода
        string converted_entry = convert_encoding(entry.full_entry, "CP1251", "UTF-8");
        out << converted_entry << "\n\n";
    }

    out.close();
    cout << "Успешно обработано " << all_entries.size() << " записей. Результат сохранен в " << output_file << endl;

    return 0;
}