#include "operations.h"
#include "charmachine.h"
#include "wordmachine.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Word currentWord;
boolean endWord;

int main() {
    FILE *fptr;
    boolean flag;
    char ops[] = {'+', '-', '/', '*'};
    char op1, op2, op3, enter;
    char file[100];
    char txt[50];
    char *path;
    char solutions[200][200];
    Word num1, num2, num3, num4;
    int i, j, k, x, y, z, a, b, c, d, count, count1, pilihan;
    int nums[] = {0, 0, 0, 0};
    int buffer3[] = {0, 0, 0};
    int buffer2[] = {0, 0};
    int buffer[] = {0};

    printf("Pilih cara menentukan 4 angka: \n");
    printf("1. Program otomatis mengenerate angka\n");
    printf("2. Masukan manual dari pengguna/user\n");
    printf(">> ");
    scanf("%d", &pilihan);

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
        scanf("%c", &enter);
        STARTWORD();
        count1 = 0;
        while (!endWord) {
            if (!isInt(currentWord) && !isAlphabet(currentWord)) {
                flag = false;
            }
            if (count1 == 0) {
                num1 = currentWord;
            } else if (count1 == 1) {
                num2 = currentWord;
            } else if (count1 == 2) {
                num3 = currentWord;
            } else if (count1 == 3) {
                num4 = currentWord;
            }
            count1++;
            ADVWORD();
        }
        if (count1 > 4) {
            flag = false;
        }

        while (!flag) {
            flag = true;
            count1 = 0;
            // scanf("%c", &enter);
            printf("Masukan tidak sesuai!\n");
            printf("Masukan hanya huruf (A, J, Q, K) atau angka[2-10]!\n");
            printf("Masukkan 4 buah angka: \n");
            printf(">> ");
            currentChar = ' ';
            STARTWORD();
            while (!endWord) {
                if (!isInt(currentWord) && !isAlphabet(currentWord)) {
                    flag = false;
                }
                if (count1 == 0) {
                    num1 = currentWord;
                } else if (count1 == 1) {
                    num2 = currentWord;
                } else if (count1 == 2) {
                    num3 = currentWord;
                } else if (count1 == 3) {
                    num4 = currentWord;
                }
                count1++;
                ADVWORD();
            }
            if (count1 > 3) {
                flag = false;
            }
        }

        if (isAlphabet(num1)) {
            nums[0] = transformToNumber(num1);
        } else { 
            nums[0] = transformToInt(num1);
        }
        if (isAlphabet(num2)) {
            nums[1] = transformToNumber(num2);
        } else { 
            nums[1] = transformToInt(num2);
        }
        if (isAlphabet(num3)) {
            nums[2] = transformToNumber(num3);
        } else { 
            nums[2] = transformToInt(num3);
        }
        if (isAlphabet(num4)) {
            nums[3] = transformToNumber(num4);
        } else { 
            nums[3] = transformToInt(num4);
        }
        printf("4 angka masukan pengguna: ");
        printf("%d %d %d %d\n", nums[0], nums[1], nums[2], nums[3]);
    }

    count = 0;
    for (i = 0; i < 4; i++) {
        a = nums[i];
        remove_element(nums, a, buffer3, 4);
        for (j = 0; j < 3; j++) {
            b = buffer3[j];
            remove_element(buffer3, b, buffer2, 3);
            for (k = 0; k < 2; k++) {
                c = buffer2[k];
                remove_element(buffer2, c, buffer, 2);
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

    if (count == 0) {
        printf("Tidak dapat menemukan solusi:(");
    } else {
        printf("Banyaknya solusi: %d\n", count);
        for (int i = 0; i < count; i++) {
            printf("%d. ", i+1);
            printf("%s", solutions[i]);
        }
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