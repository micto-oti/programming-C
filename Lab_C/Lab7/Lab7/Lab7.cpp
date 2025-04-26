#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // Для qsort


struct humen {
    std::string firstName;
    std::string secondName;
    std::string lastName;
    int birthYear;
};

// Функция сравнения для qsort (должна возвращать int и принимать const void*)
int compareHumen(const void* a, const void* b) {
    const humen* humenA = static_cast<const humen*>(a);
    const humen* humenB = static_cast<const humen*>(b);

    if (humenA->birthYear < humenB->birthYear) return -1;
    if (humenA->birthYear > humenB->birthYear) return 1;
    return 0;
}

int main() {
    const int INITIAL_SIZE = 10;
    int capacity = INITIAL_SIZE;
    int count = 0;

    // Динамический массив вместо vector
    humen* people = new humen[capacity];

    // Чтение данных из файла
    std::ifstream inFile("data.txt");
    if (!inFile) {
        std::cerr << "Не удалось открыть файл для чтения." << std::endl;
        return 1;
    }

    humen temp;
    while (inFile >> temp.firstName >> temp.secondName >> temp.lastName >> temp.birthYear) {
        // Если массив заполнен, увеличиваем его размер
        if (count == capacity) {
            capacity *= 2;
            humen* newPeople = new humen[capacity];
            for (int i = 0; i < count; ++i) {
                newPeople[i] = people[i];
            }
            delete[] people;
            people = newPeople;
        }
        people[count++] = temp;
    }
    inFile.close();

    // Сортировка массива с помощью qsort
    qsort(people, count, sizeof(humen), compareHumen);

    // Запись результата в файл
    std::ofstream outFile("output.txt");
    if (!outFile) {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;
        delete[] people;
        return 1;
    }

    for (int i = 0; i < count; ++i) {
        outFile << people[i].firstName << " "
            << people[i].secondName << " "
            << people[i].lastName << " "
            << people[i].birthYear << std::endl;
    }
    outFile.close();

    // Освобождение памяти
    delete[] people;

    std::cout << "Данные успешно обработаны и записаны в output.txt" << std::endl;
    std::cout << "Обработано записей: " << count << std::endl;

    return 0;
}




















































/*
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




*/