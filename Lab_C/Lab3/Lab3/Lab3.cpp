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

	size_t lenght = strlen(u_str);

	for (size_t i = 0; i < lenght; i++) {
		if (u_str[i] == 'a') 
		{
			u_str[i] = 'A';
		} 
		if (u_str[i] == 'b')
		{
			u_str[i] = 'B';
		}
		if (u_str[i] == '.')
		{
			u_str[i] = '!';
		}
	}

	printf("\nModified str: %s\n", u_str);



	return 0;
}