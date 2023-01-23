/* File: operations.h */
/* Deskripsi: berisi fungsi-fungsi operasi yang dapat membantu program utama */

#include <stdio.h>
#include "boolean.h"

float eval(float a, float b, char op);
/* Menghitung hasil dari operasi float a dengan float b dengan operator char op */

void remove_element(int arr[], int index, int buffer[], int size);
/* Prekondisi: arr memiliki elemen dan tidak kosong */
/* F.S.: terbentuk array buffer yang berisi elemen array arr tanpa num di dalamnya */


boolean same(char *s1 , char *s2);

boolean isAlphabet(char num[]);
/* Menghasilkan true jika x adalah huruf A, J, Q, atau K, false jika tidak */

boolean isInt(char num[]);
/* Menghasilkan true jika x adalah angka (2-10)*/

int transformToInt(char num[]);
/* Menghasilkan nilai integer dari currentword yang berupa word number */

int transformToNumber(char num[]);
/* Menghasilkan nilai integer dari word x yang berupa huruf A, J, Q, atau K */
/* A = 1 
   J = 11 
   Q = 12
   K = 13 */