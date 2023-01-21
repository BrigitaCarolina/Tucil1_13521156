#include <stdio.h>

float eval(float a, float b, char op) {
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
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] != num) {
            buffer[count] = arr[i];
            count++;
        }
    }
}
// void rotate(int arr[]) {
//     int temp = arr[0];
//     int i;
//     for (i = 0; i < 3; i++) {
//         arr[i] = arr[i+1];
//     }
//     arr[i] = temp;
// }

// int main() {
//     int nums[] = {1, 2, 3, 4};
//     int buffer3[] = {0, 0, 0};
//     remove_element(nums, 2, buffer3, 4);
//     for (int i = 0; i < 3; i++) {
//         printf("%d\n", buffer3[i]);
//     }
//     printf("%d\n", nums[0]);
//     rotate(nums);
//     printf("%d\n", nums[0]);
//     rotate(nums);
//     printf("%d\n", nums[0]); // it gets 3 as its number the next thing is gonna be 4 but then it becomes 1, so you have to rotate around 3 times
//     rotate(nums); // you'll get 
//     printf("%d\n", nums[0]);
// }