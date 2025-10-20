#include <iostream>
using namespace std;

void partial_sum(const double input[20], double output[20]) {
    output[0] = input[0];
    for (int i=1; i<20; ++i) {
        output[i] = output[i-1] + input[i];
    }
}

int main(void) {
    double input[20];
    double output[20];
    
    for (int i=0; i<20; ++i) {
        input[i] = i+1;
    }

    partial_sum(input, output);

    for (int i=0; i<20; ++i) {
        cout << output[i] << " ";
    }
    cout << endl;

    return 0;
}