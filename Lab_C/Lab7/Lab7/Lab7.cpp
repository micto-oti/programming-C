#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>



struct human {
	std::string year;
	double year;
};

int SortByYear(const void *a, const void *b) {
	return ((human*)a)->year - ((human*)b)->year;
}


int main() {

	FILE* input_1 = fopen("data.txt", "r");
	FILE* output_1 = fopen("output.txt", "w");

	if (input_1 == NULL || output_1 == NULL) {
		printf("невозможно открыть: 'data.txt' или 'output1.txt'");
		return 1;
	}


	char** strings = NULL;
	int Humans = 0;
	char name[50], surname[50];
	int year;

	while (fscanf(input_1, "%s %s %d", name, surname, year)) {


	}







	/*std::vector<human>record;
	std::ifstream file("input.txt");

	std::string line;
	while (std::getline(file, line)) {

	}*/






























	//char buffer[100];

	//FILE* input_1 = fopen("data.txt", "r");
	//FILE* output_1 = fopen("output.txt", "w");

	//if (input_1 == NULL || output_1 == NULL) {
	//	printf("невозможно открыть: 'data.txt' or 'output1.txt'");
	//	//return 1;
	//}








}