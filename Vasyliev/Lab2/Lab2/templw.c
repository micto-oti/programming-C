#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/time.h>
// ����� ��� ��� ���������� ����������
typedef struct word {
  int count;
  char *Word;
 } WORD;
 
int cmpword_alpha(WORD *, WORD *);
int cmpword_quant(WORD *, WORD *);

WORD words[100000];

int totalw=0;

int main(int ac, char *av[])
{
  FILE *OUT1, *OUT2, *IN;
  char *pword;
  // ����� ������� ����� ��� ������,
  // �������� �� �����,  ������������� ���������� � �.�.
  if (ac<2)
  {
    printf ("�� ������ ������� ������ ������!\n"); exit (0);
  }
  while (--ac) // ���� �� ������ ������
  {
   IN=fopen(av[ac],"r");
   printf("�������������� ���� %s\n",av[ac]);
   // ��������� ��������� ����
   while ((pword=getword(IN))!=NULL)
    { // .........................
      // �������� � ����������� ������
      // ��������� � ������ � ����������� totalw
      // ��� ����������� ������� ���
      // ����������� � ������� �����
      //
      //     break;  // ������ ��� ��������
    }
   fclose(IN);
  }
 qsort(words,totalw,sizeof(WORD *),
        (int (*)(const void *, const void *))cmpword_alpha );
 // ����� ����� �������
 qsort(words,totalw,sizeof(WORD *),
        (int (*)(const void *, const void *))cmpword_quant );
 // ����� ����� �������
return 0; 
}
char *getword(FILE *F)
{ char *s; int c;
 // ��������� ���� ����� �� ����� F
 //................. 
 // return NULL ���� ���� ��������
 return s;
}
int cmpword_alpha(WORD *w1,  WORD *w2)
{
  ;
}
int cmpword_quant(WORD *w1,  WORD *w2)
{
  ;
}
