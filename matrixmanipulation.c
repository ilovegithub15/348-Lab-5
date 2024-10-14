#include <stdio.h>
#define SIZE 5
void addMatrices(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}