#include <stdio.h>
#include "boolean.h"
#include <string.h>

float eval(float a, float b, char op) {
/* Menghitung hasil dari operasi float a dengan float b dengan operator char op */
    if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else if (op == '/') {
        return a / b;
    } else if (op == '*') {
        return a * b;
    }
}

void remove_element(int arr[], int index, int buffer[], int size) {
/* Prekondisi: arr memiliki elemen dan tidak kosong */
/* F.S.: terbentuk array buffer yang berisi elemen array arr tanpa num di dalamnya */
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (i != index) {
            buffer[count] = arr[i];
            count++;
        }
    }
}

boolean same(char *s1 , char *s2) {
/* Menghasilkan true jika string s1 sama dengan string s2 */
    if (strlen(s1) == strlen(s2)) {
        for (int i = 0; i < strlen(s1); i++) {
            if (s1[i] != s2[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

boolean isAlphabet(char num[]) {
/* Menghasilkan true jika x adalah huruf A, J, Q, atau K, false jika tidak */
    if (same(num, "A") || 
        same(num, "J")||
        same(num, "Q")||
        same(num, "K")) {
        return true;
    }
    return false;
}

boolean isInt(char num[]) {
/* Menghasilkan true jika x adalah angka (2-10)*/
    if (same(num, "2") || 
        same(num, "3")||
        same(num, "4")||
        same(num, "5")||
        same(num, "6")||
        same(num, "7")||
        same(num, "8")||
        same(num, "9")||
        same(num, "10")) {
            return true;
        }
    return false;
}

int transformToInt(char num[]) {
    if (same(num, "2")) {
        return 2;
    } else if (same(num, "3")) {
        return 3;
    } else if (same(num, "4")) {
        return 4;
    } else if (same(num, "5")) {
        return 5;
    } else if (same(num, "6")) {
        return 6;
    } else if (same(num, "7")) {
        return 7;
    } else if (same(num, "8")) {
        return 8;
    } else if (same(num, "9")) {
        return 9;
    } else if (same(num, "10")) {
        return 10;
    }
}

int transformToNumber(char num[]) {
/* Menghasilkan nilai integer dari word x yang berupa huruf A, J, Q, atau K */
/* A = 1 
   J = 11 
   Q = 12
   K = 13 */
    if (same(num, "A")) {
        return 1;
    } else if (same(num, "J")) {
        return 11;
    } else if (same(num, "Q")) {
        return 12;
    } else if (same(num, "K")) {
        return 13;
    }
}