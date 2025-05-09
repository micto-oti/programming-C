#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
Создать текстовый файл с записями, включающие имя/фамилию человека, год рождения, пол и рост (в метрах). 
Упорядочить элементы по году рождения, имени/фамилии, полу или росту. 
Вывести результат. 
Указать элемент, по которому следует упорядочить, через консоль. 
А также реализовать возможность задавать несколько полей для упорядочивания.
*/


/* структура */
typedef struct {
	char name[50]; // имя
	char lastname[50]; // фамилия
	int year; // год рождения
	char gend[3]; // пол
	float height; // рост
} Human;

/* функция сравнения */
int compare_pip(const Human* a, const Human* b, const char* choose) {
	for (int i = 0; choose[i] != '\0'; i++) {
		switch (choose[i]) {
		case 'y': // год рождения
			if (a->year != b->year) {
				return a->year - b->year;
			}
			break;
		case 'n': // имя
		{
			int cmp = strcmp(a->name, b->name);
			if (cmp != 0) return cmp;
			break;
		}
		case 'l': // фамилия
		{
			int cmp = strcmp(a->lastname, b->lastname);
			if (cmp != 0) return cmp;
			break;
		}
		case 'g': // пол
			if (a->gend != b->gend) {
				return a->gend - b->gend;
			}
			break;
		case 'h': // рост
			if (a->height != b->height) {
				return (a->height > b->height) ? 1 : -1;
			}
			break;
		}
	}
	return 0;
}

int main() {
	FILE* data = fopen("data.txt","r");
	FILE* output = fopen("output.txt", "w");
	if (!data || !output){
		printf("не удалось открыть data.txt или otput.txt");
		return 1;
	}

	char buffer[256];
	int count = 0;
	while (fgets(buffer, sizeof(buffer), data)) { // определяем размер файла ввода
		count++;
	}
	rewind(data); // перенос в начало

	Human* people = (Human*)malloc(count * sizeof(Human));
	if (!people) {
		printf("Ошибка выделения памяти\n");
		fclose(data);
		return 1;
	}

	// чтение данных из файла
	int cnt = 0;
	while (fscanf(data, "%49s %49s %d %2s %f",
		people[cnt].name,
		people[cnt].lastname,
		&people[cnt].year,
		&people[cnt].gend,
		&people[cnt].height) == 5) {
		cnt++;
	}
	fclose(data);

	// по каким критериям сортируем
	char choose[10];
	printf("Введите критерии сортировки (y - год, n - имя, l - фамилия, g - пол, h - рост) (по порядку желаемой сортировки при использовании нескольких критериев): ");
	scanf("%9s", choose);

	// сортировка
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (compare_pip(&people[j], &people[j + 1], choose) > 0) {
				Human temp = people[j];
				people[j] = people[j + 1];
				people[j + 1] = temp;
			}
		}
	}

	// запись результата в файл
	printf("\nотсортировано записей: %d\nрезультат записан в \"output.txt\"\n", count);
	for (int i = 0; i < count; ++i) {
		fprintf(output, "%s %s %d %s %.2f\n", people[i].name, people[i].lastname, people[i].year, people[i].gend, people[i].height);
	}
	fclose(output);

	free(people);
	return 0;
}
