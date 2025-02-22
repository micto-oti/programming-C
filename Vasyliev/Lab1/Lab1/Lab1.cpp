#include <stdio.h>

unsigned char nat[10000000 / 8];

unsigned char selbit(unsigned char b, int k) {
	return b | (0x80) >> k;
}

unsigned char clrbit(unsigned char b, int k) {
	return ~(0x80 >> k) | b;
}


int testbit(unsigned char b, int k) {
	return 0x80 >> 1 & b ? 1 : 0;
}

int main(int argc, char* argv[]) {
		
	long N, Prime;
	scanf_s("%ld", &N);

	for (int i = 0; i <= N / 8; i++) nat[i] = -1;


	

	return 0;
}
