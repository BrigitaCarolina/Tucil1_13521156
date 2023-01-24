#include "operations.h"
#include "boolean.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    clock_t start, end;
    float execution_time;
    FILE *fptr;
    FILE *pita;
    boolean flag;
    char ops[] = {'+', '-', '/', '*'};
    char op1, op2, op3, enter, ch;
    char file[100];
    char txt[50];
    char *path;
    char solutions[200][200];
    char num[10];
    char num_array[10][10];
    int i, j, k, x, y, z, a, b, c, d, count, count1, pilihan, retval, count_i, count_j;
    int nums[] = {0, 0, 0, 0};
    int buffer3[] = {0, 0, 0};
    int buffer2[] = {0, 0};
    int buffer[] = {0};

    printf("**********************************\n");
    printf("*                                *\n");
    printf("*         24 GAME SOLVER         *\n");
    printf("*                                *\n");
    printf("**********************************\n");
    printf("Pilih cara menentukan 4 angka: \n");
    printf("1. Program otomatis mengenerate angka\n");
    printf("2. Masukan manual dari pengguna/user\n");
    printf(">> ");
    scanf("%d", &pilihan);

    while (pilihan != 1 && pilihan != 2) {
        printf("Masukan tidak valid! Hanya masukkan 1 atau 2!\n");
        printf("Pilih cara menentukan 4 angka: \n");
        printf("1. Program otomatis mengenerate angka\n");
        printf("2. Masukan manual dari pengguna/user\n");
        printf(">> ");
        scanf("%d", &pilihan);
    }

    if (pilihan == 1) {
        srand((unsigned int) time(NULL));
        printf("4 angka yang ter-generate: ");
        for (int i = 0; i < 4; i++) {
            nums[i] = (rand() % 13) + 1;
            printf("%d ", nums[i]);
        }
        printf("\n");
    } else if (pilihan == 2) {
        flag = true;
        printf("Masukkan 4 buah angka: \n");
        printf(">> ");
        count1 = 0;
        count_i = 0;
        count_j = 0;
        scanf("%c", &enter);
        ch = getchar();
        while (ch != '\n') {
            if (ch == ' ') {
                num_array[count_i][count_j] = '\0';
                count_i++;
                count_j = 0; 
            } else {
                num_array[count_i][count_j] = ch;
                count_j++;
            }
            ch = getchar();
        }

        if (count_i > 3) {
            printf("Hanya masukan sejumlah 4 buah angka atau huruf!\n");
            flag = false;
        }


        if (flag) {
            for (int count2 = 0; count2 < 4; count2++) {
                if (!isInt(num_array[count2]) && !isAlphabet(num_array[count2])) {
                    flag = false;
                }
            }
            if (!flag) {
                printf("Masukan tidak valid, masukkan hanya angka atau huruf (A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K)!\n");
            }
        }

        while (!flag) {
            flag = true;
            printf("Masukkan 4 buah angka: \n");
            printf(">> ");
            count1 = 0;
            while (count1 < 4 && scanf("%s", num) != EOF) {
                strcpy(num_array[count1], num);
                count1++;
            }
            for (int count2 = 0; count2 < 4; count2++) {
                if (!isInt(num_array[count2]) && !isAlphabet(num_array[count2])) {
                    flag = false;
                }
            }
            if (!flag) {
                printf("Masukan tidak valid, masukkan hanya angka atau huruf (A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K)!\n");
            }
        }

        if (isAlphabet(num_array[0])) {
            nums[0] = transformToNumber(num_array[0]);
        } else { 
            nums[0] = transformToInt(num_array[0]);
        }
        if (isAlphabet(num_array[1])) {
            nums[1] = transformToNumber(num_array[1]);
        } else { 
            nums[1] = transformToInt(num_array[1]);
        }
        if (isAlphabet(num_array[2])) {
            nums[2] = transformToNumber(num_array[2]);
        } else { 
            nums[2] = transformToInt(num_array[2]);
        }
        if (isAlphabet(num_array[3])) {
            nums[3] = transformToNumber(num_array[3]);
        } else { 
            nums[3] = transformToInt(num_array[3]);
        }
        printf("4 angka masukan pengguna: ");
        printf("%d %d %d %d\n", nums[0], nums[1], nums[2], nums[3]);
    }

    start = clock();
    count = 0;
    for (i = 0; i < 4; i++) {
        a = nums[i];
        remove_element(nums, i, buffer3, 4);
        for (j = 0; j < 3; j++) {
            b = buffer3[j];
            remove_element(buffer3, j, buffer2, 3);
            for (k = 0; k < 2; k++) {
                c = buffer2[k];
                remove_element(buffer2, k, buffer, 2);
                d = buffer[0];
                for (x = 0; x < 4; x++) {
                    op1 = ops[x];
                    for (y = 0; y < 4; y++) {
                        op2 = ops[y];
                        for (z = 0; z < 4; z++) {
                            op3 = ops[z];
                            if ((eval(eval(eval(a, b, op1), c, op2), d, op3)) == 24) {
                                sprintf(solutions[count], "((%d %c %d) %c %d) %c %d\n", a, op1, b, op2, c, op3, d);
                                count++;
                            }
                            if (eval(eval(a, b, op1), eval(c, d, op3), op2) == 24) {
                                sprintf(solutions[count], "(%d %c %d) %c (%d %c %d)\n", a, op1, b, op2, c, op3, d); 
                                count++;
                            }
                            if (eval(eval(a, eval(b, c, op2), op1), d, op3) == 24) {
                                sprintf(solutions[count], "(%d %c (%d %c %d)) %c %d\n", a, op1, b, op2, c, op3, d);
                                count++;
                            } 
                            if (eval(a, (eval(eval(b, c, op2), d, op3)), op1) == 24) {
                                sprintf(solutions[count], "%d %c ((%d %c %d) %c %d)\n", a, op1, b, op2, c, op3, d);
                                count++;
                            } 
                            if (eval(a, (eval(b, eval(c, d, op3), op2)), op1) == 24) {
                                sprintf(solutions[count], "%d %c (%d %c (%d %c %d))\n", a, op1, b, op2, c, op3, d);
                                count++;
                            }
                        }
                    }
                }
            }
        }
    }
    end = clock();
    execution_time = ((float)(end - start))/CLOCKS_PER_SEC;

    if (count == 0) {
        printf("Tidak ada solusi!\n");
        printf("Execution time: %f seconds\n", execution_time);
    } else {
        printf("Banyaknya solusi yang ditemukan: %d\n", count);
        for (int i = 0; i < count; i++) {
            printf("%d. ", i+1);
            printf("%s", solutions[i]);
        }
        printf("Execution time: %f seconds\n", execution_time);
        printf("Apakah ingin menyimpan solusi?\n");
        printf("1. Ya\n");
        printf("2. Tidak\n");
        printf(">> ");
        scanf("%d", &pilihan);

        if (pilihan == 1) {
            printf("Masukkan nama file dengan ekstensi .txt\n");
            printf(">> ");
            scanf("%s", txt);
            path = "..\\test\\";
            i = 0;
            while (path[i] != '\0') {
                file[i] = path[i];
                i++;
            }
            j = 0;
            while (txt[j] != '\0') {
                file[i] = txt[j];
                i++;
                j++;
            }
            file[i] = '\0';
            printf("%s", file);

            fptr = fopen(file, "w");
            for (int i = 0; i < count; i++) {
                fprintf(fptr, "%s", solutions[i]);
            }
            fclose(fptr);
        } else if (pilihan == 2) {
            printf("Terima kasih telah menggunakan 24 game solver:)");
        }
    }
    
}