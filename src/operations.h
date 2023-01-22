/* File: operations.h */
/* Deskripsi: berisi fungsi-fungsi operasi yang dapat membantu program utama */

#include <stdio.h>
#include "boolean.h"
#include "wordmachine.h"

float eval(float a, float b, char op);
/* Menghitung hasil dari operasi float a dengan float b dengan operator char op */

void remove_element(int arr[], int num, int buffer[], int size);
/* Prekondisi: arr memiliki elemen dan tidak kosong */
/* F.S.: terbentuk array buffer yang berisi elemen array arr tanpa num di dalamnya */

int transformToInt(Word x);
/* Menghasilkan nilai integer dari currentword yang berupa word number */

boolean isAlphabet(Word x);
/* Menghasilkan true jika x adalah huruf A, J, Q, atau K, false jika tidak */

boolean isInt(Word x);
/* Menghasilkan true jika x adalah angka (2-10)*/

int transformToNumber(Word x);
/* Menghasilkan nilai integer dari word x yang berupa huruf A, J, Q, atau K */
/* A = 1 
   J = 11 
   Q = 12
   K = 13 */