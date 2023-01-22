#include <stdio.h>
#include "boolean.h"
#include "wordmachine.h"

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

void remove_element(int arr[], int num, int buffer[], int size) {
/* Prekondisi: arr memiliki elemen dan tidak kosong */
/* F.S.: terbentuk array buffer yang berisi elemen array arr tanpa num di dalamnya */
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] != num) {
            buffer[count] = arr[i];
            count++;
        }
    }
}

int transformToInt(Word x){
/* Menghasilkan nilai integer dari currentword yang berupa word number */
    int i = 0;
    int result = 0;
    while(i < x.Length){
        result = result * 10 + (x.TabWord[i] - '0');
        i++;
    }
    return result;
}

boolean isAlphabet(Word x) {
/* Menghasilkan true jika x adalah huruf A, J, Q, atau K, false jika tidak */
    if (x.Length == 1) {
        if (x.TabWord[0] == 'A') {
            return true;
        } else if (x.TabWord[0] == 'J') {
            return true;
        } else if (x.TabWord[0] == 'Q') {
            return true;
        } else if (x.TabWord[0] == 'K') {
            return true;
        }
    }
    return false;
}

boolean isInt(Word x) {
/* Menghasilkan true jika x adalah angka (2-10)*/
    if (x.Length == 1) {
        if (x.TabWord[0] == '2' ||
            x.TabWord[0] == '3' ||
            x.TabWord[0] == '4' ||
            x.TabWord[0] == '5' ||
            x.TabWord[0] == '6' ||
            x.TabWord[0] == '7' ||
            x.TabWord[0] == '8' ||
            x.TabWord[0] == '9') {
                return true;
            }
    } else if (x.Length == 2) {
        if (x.TabWord[0] =='1' && x.TabWord[1] == '0') {
            return true;
        }
    }
    return false;
}

int transformToNumber(Word x) {
/* Menghasilkan nilai integer dari word x yang berupa huruf A, J, Q, atau K */
/* A = 1 
   J = 11 
   Q = 12
   K = 13 */
    if (x.TabWord[0] == 'A') {
        return 1;
    } else if (x.TabWord[0] == 'J') {
        return 11;
    } else if (x.TabWord[0] == 'Q') {
        return 12;
    } else if (x.TabWord[0] == 'K') {
        return 13;
    }
}