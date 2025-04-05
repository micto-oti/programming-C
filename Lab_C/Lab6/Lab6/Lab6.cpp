#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {

	FILE* file1 = fopen("data.txt", "r");
	FILE* output1 = fopen("output.txt", "w");
	
	int year;
	char buffer[256];

	if (file1 == NULL || output1 == NULL) {
		printf("Can't open: 'data.txt' or 'output1.txt'");
		return 1;
	}

	while (fgets(buffer, sizeof(buffer), file1) != NULL) {
		char* last_str = strrchr(buffer, '@');
		
		if (last_str == NULL) continue;

		printf("%s", last_str-4);

		/*year = atoi(last_str + 4);

		if (year > 1980) {
			fprintf(output1, "%s", buffer);
			printf("%s", buffer);
		}*/

	}



	return 0;
}
