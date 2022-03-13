#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>

//Дано двійковий файл дійсних чисел(тип doubl). Знайти їх середнє арифметичне і вивести значення у текстовий файл.

void to_get_the_num(char num[], char line_for_num[], int* double_of_num, int length);

int main() {
	FILE* numbers = fopen("double2.bin", "r");
    char filename[SIZE] = "";
    char line_for_num[SIZE] = "";
    char num[SIZE];
    double arr[SIZE];
    int i = 0, double_of_num = 0;

    printf("Enter the name of the file you want to open:\n");
    do {
        fgets(filename, 256, stdin);
        if (filename[0] == '\n')
        {
            printf("You entered empty string: ");
        }
    } while (filename[0] == '\n');
    filename[strlen(filename) - 1] = ' ';

    if ((numbers = fopen(filename, "r")) == NULL)
    {
        printf("Mistake with opening file %s!\n", filename);
        return 1;
    }

    printf("The file was successfully created or it could be opened!\n");

    while (fgets(num, SIZE, nombers)) {
        length = strlen(num) - 1;
        to_get_the_num(num, line_for_num, &double_of_num, length);
        arr[i] = double_of_num;
        i++
        printf("%d\n", A[i]);
    }

    fclose(numbers);
    return 0;
}

void to_get_the_num(char num[], char line_for_num[], int* double_of_num, int length) {
    int k = 0;
    int w;
    int g = 9;

    for (int i = 0; i < length; i++) {
        if (num[i] >= '0' && num[i] <= '9') {
            for (int j = i; j < length; j++) {

                line_for_num[k] = num[i];
                i++;
                k++;
                w = i;
            }
            break;
        }
    }

    if (num[w] != line_for_num[g]) {
        line_for_num[g] = NULL;
    }

    int q = 0;
    *double_of_num = 0;

    for (int i = k - 1; i >= 0; i--) {
        *double_of_num += (line_for_num[i] - 48) * pow(10, q);
        q++;
    }
}