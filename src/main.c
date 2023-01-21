#include "operations.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, k, x, y, z, a, b, c, d, count;
    char ops[] = {'+', '-', '/', '*'};
    char op1, op2, op3;
    int nums[] = {8, 3, 4, 5};
    int buffer3[] = {0, 0, 0};
    int buffer2[] = {0, 0};
    int buffer[] = {0};
    char *solutions[100];

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
                                printf("((%d %c %d) %c %d) %c %d\n", a, op1, b, op2, c, op3, d);
                                count++;
                            }
                            if (eval(eval(a, b, op1), eval(c, d, op3), op2) == 24) {
                                printf("(%d %c %d) %c (%d %c %d)\n", a, op1, b, op2, c, op3, d); 
                                count++;
                            }
                            if (eval(eval(a, eval(b, c, op2), op1), d, op3) == 24) {
                                printf("(%d %c (%d %c %d) %c %d\n", a, op1, b, op2, c, op3, d);
                                count++;
                            } 
                            if (eval(a, (eval(eval(b, c, op2), d, op3)), op1) == 24) {
                                printf("%d %c ((%d %c %d) %c %d)\n", a, op1, b, op2, c, op3, d);
                                count++;
                            } 
                            if (eval(a, (eval(b, eval(c, d, op3), op2)), op1) == 24) {
                                printf("%d %c (%d %c (%d %c %d)\n", a, op1, b, op2, c, op3, d);
                                count++;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("Banyaknya solusi: %d", count);
}