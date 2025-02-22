unsigned char nat[10000000];
#include <stdio.h>

#define setbit(b,k) ((b)=(b)|0x80>>(k))
#define clrbit(b,k) ((b)=(b)&(~(0x80>>(k))))
#define TestBit(b,k) (((b)&0x80>>(k))?1:0)
#define DEBUG
//#undef DEBUG

int main(int argc, char **argv) {

	long N, Prime;
	printf("input N:\n");
	scanf_s("%ld", &N);

	for (int i = 0; i < N; i++) {
		nat[i] = 0xff;
	}
//#ifdef Debug
	nat[0] = 0;
	setbit(nat[0], 2);
	setbit(nat[0], 6);
	printf("%x\n", nat[0]);
//#endif DEBUG

	return 0;
}
