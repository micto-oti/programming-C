#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

struct humen {
    std::string firstName;
    std::string secondName;
    std::string lastName;
    int birthYear;
};

// Функция для сравнения двух структур humen по году рождения
bool compareHumen(const humen& a, const humen& b) {
    return a.birthYear < b.birthYear;
}

int main() {
    std::vector<humen> people;

    // Чтение данных из файла
    std::ifstream inFile("data.txt");
    if (!inFile) {
        std::cerr << "Не удалось открыть файл для чтения." << std::endl;
        return 1;
    }

    std::ofstream outFile("output.txt");
    if (!outFile) {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;
        return 1;
    }

    humen temp;
    while (inFile >> temp.firstName >> temp.secondName >> temp.lastName >> temp.birthYear) {
        people.push_back(temp);
    }
    inFile.close();

    // Сортировка вектора по году рождения
    sort(people.begin(), people.end(), compareHumen);

    // Запись результата в файл
    for (const auto& person : people) {
        outFile << person.firstName << " "
            << person.secondName << " "
            << person.lastName << " "
            << person.birthYear << std::endl;
    }
    outFile.close();

    std::cout << "Данные успешно обработаны и записаны в output.txt" << std::endl;
    std::cout << "Обработано записей: " << people.size() << std::endl;

    return 0;
}

