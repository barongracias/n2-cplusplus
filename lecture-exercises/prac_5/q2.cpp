#include <iostream>
using namespace std;

int** allocateMatrix(int N) {
    int** matrix = new int*[N];

    for (int i=0; i<N; i++) {
        matrix[i] = new int[N];
    }
    return matrix;
}

void freeMatrix(int** matrix, int N) {
    for (int i=0; i<N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void multiply(int** A, int** B, int** C, int N) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            C[i][j] = 0;
            for (int k=0; k<N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main(void) {
    int N;
    cout << "Enter size N: ";
    cin >> N;
    
    int** A = allocateMatrix(N);
    int** B = allocateMatrix(N);
    int** C = allocateMatrix(N);

    cout << "Enter elements of matrix A (" << N << "x" << N << "):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of matrix B (" << N << "x" << N << "):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> B[i][j];
        }
    }

    multiply(A, B, C, N);

    cout << "Product matrix C = A x B:" << endl;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    freeMatrix(A, N);
    freeMatrix(B, N);
    freeMatrix(C, N);

    return 0;
}