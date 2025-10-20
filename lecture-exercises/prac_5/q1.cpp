#include <iostream>
using namespace std;

void calcNextRow(const int* prevRow, int* nextRow, int rowNo) {
    // first and last row starts with 1
    nextRow[0] = 1;
    nextRow[rowNo-1] = 1;

    // iterate over each row
    for (int i=1; i<(rowNo-1); i++) {
        // sum values
        nextRow[i] = prevRow[i-1] + prevRow[i];
    }
}

int main(void) {
    int rowNo;
    cout << "Enter Pascal's triangle rows" << endl;
    cin >> rowNo;

    // initialise row pointers
    int* prevRow = new int[rowNo];
    int* nextRow = new int[rowNo];
    
    cout << "Row 1: " << 1 << endl;
    // iterate from second row onwards
    for (int i=2; i<=rowNo; i++) {
        calcNextRow(prevRow, nextRow, i);

        // print first row
        cout << "Row " << i << ": ";
        for (int j=0; j<i; j++) {
            // print elements from nextrow
            cout << nextRow[j] << " ";
        }
        cout << endl;
        // memory swap
        std::swap(prevRow, nextRow);
    }
    // memory delete
    delete [] prevRow;
    delete [] nextRow;

    return 0;
}