#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <filesystem>
#include <unordered_map>

namespace fs = std::filesystem;

struct Word {
    int count;
    std::string w;
};

std::vector<Word*> words;
std::unordered_map<std::string, Word*> wordMap;

bool cmpword_alpha(const Word* a, const Word* b);
bool cmpword_quant(const Word* a, const Word* b);
std::string getword(std::ifstream& F);
void add_word(const std::string& word);

int main()
{
    std::ofstream OUT1("dict1.txt"), OUT2("dict2.txt");
    if (!OUT1 || !OUT2)
    {
        std::cerr << "Ошибка при создании файлов вывода!\n";
        return 1;
    }

    // Читаем все файлы из директории texts
    for (const auto& entry : fs::directory_iterator("texts"))
    {
        if (!entry.is_regular_file()) continue;

        std::ifstream IN(entry.path());
        if (!IN)
        {
            std::cerr << "Не удалось открыть файл " << entry.path() << "\n";
            continue;
        }

        std::cout << "Обрабатывается файл " << entry.path() << "\n";

        std::string word;
        while (!(word = getword(IN)).empty())
        {
            add_word(word);
        }
    }

    // Сортировка по алфавиту и вывод
    std::sort(words.begin(), words.end(), cmpword_alpha);
    for (const auto& w : words)
    {
        OUT1 << w->w << " " << w->count << "\n";
    }

    // Сортировка по частоте и вывод
    std::sort(words.begin(), words.end(), cmpword_quant);
    for (const auto& w : words)
    {
        OUT2 << w->w << " " << w->count << "\n";
    }

    // Освобождаем память
    for (auto& w : words)
    {
        delete w;
    }

    return 0;
}

void add_word(const std::string& word)
{
    auto it = wordMap.find(word);
    if (it != wordMap.end())
    {
        it->second->count++;
    }
    else
    {
        Word* new_word = new Word{ 1, word };
        words.push_back(new_word);
        wordMap[word] = new_word;
    }
}

std::string getword(std::ifstream& F)
{
    char c;
    std::string word;

    // Пропускаем небуквенные символы
    while (F.get(c) && !isalpha(c));

    if (!F) return "";

    // Читаем слово (буквы и цифры)
    do
    {
        word += tolower(c);
    } while (F.get(c) && isalnum(c));

    return word;
}

bool cmpword_alpha(const Word* a, const Word* b)
{
    return a->w < b->w;
}

bool cmpword_quant(const Word* a, const Word* b)
{
    return a->count > b->count; // Для сортировки по убыванию
}