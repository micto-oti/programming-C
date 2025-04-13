#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <vector>
#include <algorithm>

// Функция для вычисления НОД (алгоритм Евклида)
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    // Получаем домашнюю директорию
    const char* home_dir = getenv("HOME");
    if (home_dir == nullptr) {
        std::cerr << "Ошибка: не удалось определить домашнюю директорию." << std::endl;
        return 1;
    }

    const std::string base_dir = std::string(home_dir) + "/projects/";
    const std::string input_dir = base_dir + "Lab5-test/test_pipe/";
    const std::string my_output_dir = base_dir + "Lab5-test/test_pipe/my-test/";

    // Создаём директорию для выходных файлов, если её нет
    mkdir(my_output_dir.c_str(), 0777);

    // --- Динамическое чтение всех input-файлов ---
    DIR* dir = opendir(input_dir.c_str());
    if (dir == nullptr) {
        perror(("Ошибка открытия директории: " + input_dir).c_str());
        return 1;
    }

    std::vector<std::string> input_files;
    struct dirent* entry;

    // Собираем все файлы, начинающиеся на "input"
    while ((entry = readdir(dir)) != nullptr) {
        std::string filename = entry->d_name;
        if (filename.rfind("input", 0) == 0) { // Если имя начинается с "input"
            input_files.push_back(filename);
        }
    }
    closedir(dir);

    // Сортируем файлы по алфавиту (input01.txt, input02.txt, ...)
    std::sort(input_files.begin(), input_files.end());

    // Обрабатываем каждый найденный файл
    for (const auto& filename : input_files) {
        std::string current_input = input_dir + "/" + filename;
        std::string num_str = filename.substr(5, 2); // Извлекаем "01" из "input01.txt"
        std::string current_my_output = my_output_dir + "output" + num_str + ".txt";

        // Читаем входные данные из файла
        std::ifstream input(current_input);
        if (!input.is_open()) {
            std::cerr << "Не удалось открыть: " << current_input << std::endl;
            continue;
        }

        long long N, M;
        input >> N >> M;
        input.close();

        // Проверка корректности данных
        if (N >= M || N < 1 || M > 1e7) {
            std::cerr << "Неверные данные в файле: " << current_input << std::endl;
            continue;
        }

        // Вычисляем результат
        long long numerator = M * N;
        long long denominator = M - N;

        // Сокращаем дробь
        long long common_divisor = gcd(numerator, denominator);
        numerator /= common_divisor;
        denominator /= common_divisor;

        // Записываем результат в выходной файл
        std::ofstream my_out(current_my_output);
        if (!my_out.is_open()) {
            std::cerr << "Не удалось создать: " << current_my_output << std::endl;
            continue;
        }

        my_out << numerator << "/" << denominator << "\n";
        my_out.close();

        std::cout << "Обработан: " << current_input << " -> " << current_my_output << "\n";
            //<< " (Результат: " << numerator << "/" << denominator << ")" << std::endl;
    }

    return 0;
}