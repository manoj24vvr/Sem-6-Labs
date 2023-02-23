#include <iostream>
#include <omp.h>
#include<bits/stdc++.h>
using namespace std;
int main() {
    const int M = 4;
    const int N = 4;
    int A[M][N] = {
        {1, 2, 3, 4},
        {6, 5, 8, 3},
        {2, 4, 10, 1},
        {9, 1, 2, 5}
    };
    int B[M][N], i, j;
    int D[M][N];
    #pragma omp parallel for shared(A, B, D)
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            if (i == 0 || i == M-1 || j == 0 || j == N-1) {
                B[i][j] = A[i][j];
            } else {
                B[i][j] = ~A[i][j] + 2;
            }
            if (i == j) {
                D[i][j] = 1;
            } else {
                D[i][j] = abs(i - j) + 1;
            }
        }
    }
    cout << "Matrix A:" << endl;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Matrix B:" << endl;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Matrix D:" << endl;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            cout << D[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
