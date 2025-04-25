#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>



struct human {
	char name[50];
	char surname[50];
	int B_year;
};

int SortByYear(const void *a, const void *b) {
	const struct human* humanA = (const struct human*)a;
	const struct human* humanB = (const struct human*)b;

	return humanA->B_year - humanB->B_year;
}


int main() {
	std::vector<int> years;

	FILE* input_1 = fopen("data.txt", "r");
	FILE* output_1 = fopen("output.txt", "w");

	if (input_1 == NULL || output_1 == NULL) {
		printf("невозможно открыть: 'data.txt' или 'output1.txt'");
		return 1;
	}
	
	struct human *people = NULL;
	int Humans = 0;
	char name[50], surname[50];
	int year;

	while (fscanf(input_1, "%49s %49s %49d", name, surname, &year) == 3) {
		struct human *temp = (human*)realloc(people, (Humans + 1) * sizeof(struct human));
		
		years.push_back(year);
		/*people = temp;
		strcpy(people[Humans].name, name);
		strcpy(people[Humans].surname, surname);
		people[Humans].B_year = year;*/
		Humans++;


	}
	

	fclose(input_1);

	/*qsort(people, Humans, sizeof(struct human), SortByYear);*/

	printf("Отсортировано по году рождения:\n");
	for (int i = 0; i < Humans; i++) {
		printf("%s %s, %d\n", people[i].name, people[i].surname, people[i].B_year);
	}

	free(people);
	return 0;








}