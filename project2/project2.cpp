#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>

void to_get_the_num(char num[], char line_for_num[], int* int_of_num, int length) {
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
    *int_of_num = 0;

    for (int i = k - 1; i >= 0; i--) {
        *int_of_num += (line_for_num[i] - 48) * pow(10, q);
        q++;
    }
}

int main() {
	FILE* numbers = fopen("numbers.txt", "r");
    char num[SIZE];
    char filename[SIZE] = "";
    char line_for_num[SIZE] = "";
	int* A;
    int N, length, int_of_num = 0, first_num;
    bool finder = false, f = true;

    printf("Enter the name of the file from which the array elements will be taken\n");
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

    printf("Enter the number of elements of array A\n");
    scanf("%d", &N);

    if (!(A = (int*)malloc(N * sizeof(int*)))) 
    {
        printf("Для такого масиву не вистачає пам'яті!");
        _getch();
        return 1;
    }


    printf("Array A:\tNew array A:\n");

    for (int i = 0; i < N; i++)
    {
        fgets(num, SIZE, numbers);
        length = strlen(num) - 1;
        to_get_the_num(num, line_for_num, &int_of_num, length);
        A[i] = int_of_num;

        printf("%d\t\t", A[i]);

        if (f) {
            if (A[i] % 2 == 0) {
                first_num = A[i];
                f = false;
            }
        }
        else {
            if (A[i] % 2 == 0) {
                A[i] += first_num;
            }
        }
        printf("%d\n", A[i]);
    }
    
    fclose(numbers);
	return 0;
}