#include <stdio.h>


void print_st(const char* str) {
	if (*str == '\0') {
		return;
	}
	printf("%c ", *str);
	print_st(str + 1);
}

void reverse(char* a)
{
	if (*a != '\0')
	{
		reverse(a + 1);
	}
	printf(" %c", *a);
}

int main() {
	char st[80];
	printf("Введите число:\n");
	fgets(st, sizeof(st), stdin);

	st[strlen(st) + 1] = "\0";

	print_st(st);
	reverse(st);

	return 1;
}