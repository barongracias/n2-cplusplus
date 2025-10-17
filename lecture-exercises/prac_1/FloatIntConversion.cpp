#include <iostream>

int main(void) {
    float c = 1e34;
    std::cout << c << std::endl;

    int b = c;
    std::cout << b << std::endl;

    return 0;
}

// assign 1e34 as float c and print
// assign integer b as c and print b

// prints 1e34 then prints 2147483647
// With optim, prints 1e34 then prints 0

// max int value is 2x10^9