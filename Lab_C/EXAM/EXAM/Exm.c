#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	
    /* #1 */

    //clock_t start = clock();

    FILE* inp = fopen("input.txt", "w");
    int i = 0;
    int N;


    printf("Введите N: ");
    scanf("%d", &N);

    int* arr;
    arr = (int*)malloc(N * sizeof(int));

    
    for (i = 0; i < N; i++) {
        fprintf(inp, "%d\n", rand() % 10); // случайное число
    }


    /* #2 */
    
    fclose(inp);
    free(arr);





    /* #3 */
    
    inp = fopen("input.txt", "r");
    FILE* N_F = fopen("output.txt", "w");

    char line[256];

    for (i = 0; i < N; i++) {
        fgets(line, 256, inp);
        arr[i] = atoi(line);
    }

    for (i = 0; i < N; i++) {
        if (arr[i] == 0) {

        }
        else if (arr[i] % 7 == 0)
        {
            fprintf(N_F, "семь\n");
        }
        else if (arr[i] % 5 == 0) {
            fprintf(N_F, "пять\n");
        }
        /* #4 */
        else if (arr[i] % 5 == 0 || arr[i] % 7 == 0) {
            fprintf(N_F, "пятьсемь\n");
        }
    }


}
