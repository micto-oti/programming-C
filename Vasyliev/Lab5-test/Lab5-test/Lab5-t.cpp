#include <stdio.h>
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>

int main() {
    const std::string input_base = "/home/u���/projects/test-pipes/input";
    const std::string output_base = "/home/user/projects/test-pipes/output";
    const std::string my_output = "/home/user/projects/my-test/output";


    long long M, N;

    long long numerator = M * N;
    long long denominator = M - N;

    FILE* output_file = fopen("/home/user/projects/Lab5-test/my-test/output", "w");
    if (output_file == NULL) {
        printf("Can't create: output.txt\n");
        return 1;
    }
    

    fprintf(output_file, "%lld/%lld\n", numerator, denominator);
    fclose(output_file);


    FILE* input_file = fopen("/home/user/projects/Lab5-test/input.txt", "r");
    if (input_file == NULL) {
        printf("Can't open: input.txt\n");
        return 1;
    }

    fscanf(input_file, "%lld %lld", &N, &M);
    fclose(input_file);


    for (int i = 1; i <= 10; ++i) { // ������� �� 01 �� 10
        // ����������� ����� � ������� ���� (01, 02, ...)
        std::string num_str = (i < 10) ? "0" + std::to_string(i) : std::to_string(i);

        // ��������� ����� �������� � ��������� ������
        std::string input_file = input_base + num_str + ".txt";
        std::string output_file = output_base + num_str + ".txt";
        std::string my_output = my_output + num_str + ".txt";


        // ��������� ������� ����
        std::ifstream input(input_file);
        if (!input.is_open()) {
            std::cerr << "������: �� ������� ������� " << input_file << std::endl;
            continue; // ����������, ���� ����� ���
        }

        //// ��������� �������� ����
        //std::ofstream output(output_file);
        //if (!output.is_open()) {
        //    std::cerr << "������: �� ������� ������� " << output_file << std::endl;
        //    input.close();
        //    continue;
        //}

        // ��������� �������� �������� ����
        std::ofstream my_out(my_output);
        if (!my_out.is_open()) {
            std::cerr << "������: �� ������� ������� " << output_file << std::endl;
            input.close();
            continue;
        }

        // ������ ������� ���� � ���������� � ��������
        std::string line;
        while (std::getline(input, line)) {
            my_out << line << "\n"; // ��� ������ ���������
        }

        // ��������� �����
        input.close();
        my_out.close();

        std::cout << "���������: " << input_file << " -> " << output_file << std::endl;
    }
   
    return 0;
}