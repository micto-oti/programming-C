#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>


struct humen {
    std::string firstName;
    std::string secondName;
    std::string lastName;
    int birthYear;
};

// функция сравнения
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

    // создание динамического массива
    humen* people = new humen[capacity];

    // чтение данных из файла и создание файла вывода
    std::ifstream inFile("data.txt");
    if (!inFile) {
        std::cerr << "Не удалось открыть файл для чтения." << std::endl;
        return 1;
    }

    std::ofstream outFile("output.txt");
    if (!outFile) {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;
        delete[] people;
        return 1;
    }

    humen temp;
    while (inFile >> temp.firstName >> temp.secondName >> temp.lastName >> temp.birthYear) {
        // если массив заполнен, увеличиваем его размер
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

    // Сортировка массива
    qsort(people, count, sizeof(humen), compareHumen);

    // Запись результата в файл
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