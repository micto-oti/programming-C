#include <stdio.h>
#include <string.h>

int main() {
    long long M, N;

    /*FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Can't open: input.txt\n");
        return 1;
    }

    fscanf(input_file, "%lld %lld", &N, &M);
    fclose(input_file);



    long long numerator = M * N;
    long long denominator = M - N;*/


    FILE* output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Can't create: output.txt\n");
        return 1;
    }

    /*fprintf(output_file, "%lld/%lld\n", numerator, denominator);
    fclose(output_file);*/

    return 0;
}