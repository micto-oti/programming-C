#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct word {
    int count;
    char* w;
} WORD;

WORD* words[100000];
int totalw = 0;

int cmpword_alpha(const void* a, const void* b);
int cmpword_quant(const void* a, const void* b);
char* getword(FILE* F);
void add_word(const char* word);

int main(int argc, char* argv[])
{
    FILE* OUT1, * OUT2, * IN;
    char* pword;

    if (argc < 2)
    {
        printf("Вы забыли указать список файлов!\n");
        exit(0);
    }

    // Открываем файлы для вывода
    OUT1 = fopen("dict1.txt", "w");
    OUT2 = fopen("dict2.txt", "w");
    if (!OUT1 || !OUT2)
    {
        printf("Ошибка при создании файлов вывода!\n");
        exit(1);
    }

    // Обрабатываем каждый файл из аргументов
    for (int i = 1; i < argc; i++)
    {
        IN = fopen(argv[i], "r");
        if (!IN)
        {
            printf("Не удалось открыть файл %s\n", argv[i]);
            continue;
        }

        printf("Обрабатывается файл %s\n", argv[i]);

        while ((pword = getword(IN)) != NULL)
        {
            add_word(pword);
            free(pword); // Освобождаем память, выделенную в getword
        }

        fclose(IN);
    }

    // Сортировка по алфавиту и вывод
    qsort(words, totalw, sizeof(WORD*), cmpword_alpha);
    for (int i = 0; i < totalw; i++)
    {
        fprintf(OUT1, "%s %d\n", words[i]->w, words[i]->count);
    }

    // Сортировка по частоте и вывод
    qsort(words, totalw, sizeof(WORD*), cmpword_quant);
    for (int i = 0; i < totalw; i++)
    {
        fprintf(OUT2, "%s %d\n", words[i]->w, words[i]->count);
    }

    // Освобождаем память и закрываем файлы
    for (int i = 0; i < totalw; i++)
    {
        free(words[i]->w);
        free(words[i]);
    }

    fclose(OUT1);
    fclose(OUT2);

    return 0;
}

void add_word(const char* word)
{
    // Проверяем, есть ли слово уже в массиве
    for (int i = 0; i < totalw; i++)
    {
        if (strcmp(words[i]->w, word) == 0)
        {
            words[i]->count++;
            return;
        }
    }

    // Если слова нет, добавляем новую запись
    WORD* new_word = malloc(sizeof(WORD));
    new_word->w = strdup(word);
    new_word->count = 1;
    words[totalw++] = new_word;
}

char* getword(FILE* F)
{
    int c;
    int buf_size = 32;
    int len = 0;
    char* buffer = malloc(buf_size * sizeof(char));

    // Пропускаем небуквенные символы
    while ((c = fgetc(F)) != EOF && !isalpha(c));

    if (c == EOF)
    {
        free(buffer);
        return NULL;
    }

    // Читаем слово (буквы и цифры)
    do
    {
        if (len + 1 >= buf_size)
        {
            buf_size *= 2;
            buffer = realloc(buffer, buf_size);
        }
        buffer[len++] = tolower(c);
    } while ((c = fgetc(F)) != EOF && (isalnum(c)));

    buffer[len] = '\0';

    // Возвращаем указатель на слово
    return buffer;
}

int cmpword_alpha(const void* a, const void* b)
{
    WORD* wa = *(WORD**)a;
    WORD* wb = *(WORD**)b;
    return strcmp(wa->w, wb->w);
}

int cmpword_quant(const void* a, const void* b)
{
    WORD* wa = *(WORD**)a;
    WORD* wb = *(WORD**)b;
    return wb->count - wa->count; // Для сортировки по убыванию
}