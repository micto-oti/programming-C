#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {


	int year;
	char buffer[256];

	FILE* file1 = fopen("data.txt", "r");
	FILE* output1 = fopen("output.txt", "w");

	if (file1 == NULL || output1 == NULL) {
		printf("невозможно открыть: 'data.txt' or 'output1.txt'");
		return 1;
	}

	while (fgets(buffer, sizeof(buffer), file1) != NULL) {
		char* last_str = strrchr(buffer, ' ');
		
		year = atoi(last_str);

		if (year > 1980) {
			fprintf(output1, "%s", buffer);
			printf("%s", buffer);
		}

	}

	return 0;
}
