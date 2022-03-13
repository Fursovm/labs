#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>

/* Написати програму пошуку
населеного пункту з
вказаною назвою у
відповідному файлі */

/*Структура для запису в неї назви населенного пункту та його населення*/
struct place
{
    char place_name[SIZE];
    int place_num;
};

/*Функція для переконвертування населення в тип integer*/
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

/*Функція для знаходження введеного населенного пункту у строчці*/
place finder_of_locality(struct place* list, int lines, char name[], int length1) {
    int j = 0;
    for (int i = 0; i < lines; i++) {
        int length2 = strlen(list[i].place_name);
        for (int k = 0; k < length1 - 1; k++)
        {
            if (list[i].place_name[k] == name[j]) {
                if (i + length1 - 1 > 0) {
                    j++;
                }
                else {
                    j = 0;
                }
            }
            if (j == length2 - 1) {
                return list[i];
            }
        }
    }
    return { "", 0 };
}

/*Функція для заповнення масиву структур з файлу*/
void get_info(struct place* list, FILE* places, int* lines) {
    char line_for_num[SIZE] = "";
    char num[SIZE] = "";
    int int_of_num = 0;
    int lines1 = 0;
    while (fgets(list[lines1].place_name, SIZE, places) && fgets(num, SIZE, places))
    {
        int length2 = strlen(num) - 1;
        to_get_the_num(num, line_for_num, &int_of_num, length2);
        list[lines1].place_num = int_of_num;
        lines1++;
    }
    *lines = lines1;
}

/*Функція виведення на консоль та додавання в новий файл відповідь*/
void answer(FILE* places, FILE* final_result, struct place* result) {
    if (result[0].place_num != 0) {
        printf("Locality %s was found in the file places.txt\nIts population is %d\n\n", result[0].place_name, result[0].place_num);
        fprintf(final_result, "Locality %s was found in the file places.txt\nIts population is %d\n\n", result[0].place_name, result[0].place_num);
    }
    else {
        printf("There is no such locality in the file places.txt!\n\n");
        fprintf(final_result, "There is no such locality in the file places.txt!\n\n");
    }
}

/*Функція виведення на консоль усіх структур*/
void all_struct(struct place* list, int lines) {
    printf("The whole file places.txt:\n");
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < strlen(list[i].place_name); j++) {
            if (list[i].place_name[j] == '\n') {
                list[i].place_name[j] = '\0';
            }
        }
        printf("%s\t%d\n", list[i].place_name, list[i].place_num);
    }
}

/*Функція виведення усіх структур у файл*/
void all_struct_in_file(FILE* final_result, struct place* list, int lines) {
    fprintf(final_result, "The whole file places.txt:\n");
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < strlen(list[i].place_name); j++) {
            if (list[i].place_name[j] == '\n') {
                list[i].place_name[j] = '\0';
            }
        }
        fprintf(final_result, "%s\t%d\n", list[i].place_name, list[i].place_num);
    }
}

int main(int argc, char* argv[]) {

    FILE* places;
    char filename[SIZE] = "";
    FILE* final_result = fopen("final_result.txt", "w");
    char helpful_line[SIZE] = "";
    char name[SIZE] = "";
    char real_filename[] = "places.txt";
    int lines = 0, j = 0;
    bool finder = false;
    int length1;

    /*Перевірка на правильне введення назви файлу*/
    if (argc < 2) {
        printf("Enter the name of the file you want to open:\n");
        do {
            fgets(filename, 256, stdin);
            if (filename[0] == '\n')
            {
                printf("You entered empty string: ");
            }
        } while (filename[0] == '\n');
        filename[strlen(filename) - 1] = ' ';
    }
    else
    {
        strcpy(filename, argv[1]);
    }

    if ((places = fopen(filename, "r")) == NULL)
    {
        printf("Mistake with opening file %s!\n", filename);
        return 1;
    }

    /*Перевірка на те, чи файл справді відкрився*/
    if (places == NULL) {
        fprintf(stderr, "Error! The places.txt file was not created or we can't open it!\n");
        return 1;
    }
    else {

        printf("The file was successfully created or it could be opened!\n");

        /*Введення назви населенного пункту, який бажаємо знайти*/
        printf("Enter the name of the locality you want to find in the places.txt file:\n");
        fgets(name, SIZE, stdin);
        length1 = strlen(name);

        struct place list[SIZE];

        /*Заповнюємо структури населеними пунктами з файлу*/
        get_info(list, places, &lines);

        struct place result[1];

        /*Шукаємо введений населений пункт у структурах*/
        result[0] = finder_of_locality(list, lines, name, length1);

        /*Видаляємо пропуски*/
        for (int i = 0; i < length1; i++) {
            if (result[0].place_name[i] == '\n') {
                result[0].place_name[i] = '\0';
            }
        }

        /*Виводимо фінальний результат та заносиму у новий файл*/
        answer(places, final_result, result);

        /*Виводимо весь файл на консоль*/
        all_struct(list, lines);

        /*Виводимо весь файл у новий файл*/
        all_struct_in_file(final_result, list, lines);
    }
    fclose(final_result);
    fclose(places);
    return 0;
}
