#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define _countof(arr) (sizeof(arr) / sizeof(arr[0]))


/*
Ввести с консоли строку символов произвольной длины (до 80 символов). Поменять в ней все маленькие символы ‘a’ и ‘b’ на заглавные и вывести на консоль полученную строку.
*/

int main(int argc, char argv[]) 
{
	char u_str[80];

	printf("Input str:");
	scanf_s("%s", u_str, (unsigned)_countof(u_str));

	for (int i; i < 80; i++) {
		if (strchr(u_str, "a") == 0) {
			u_str[i] = "A";
		}
	}



	return 0;
}