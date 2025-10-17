#include <iostream>

int main(void){
    int a = 5;
    int b = 2;
    int c = a*b + 5;

    std::cout << "c = " << c << std::endl;
    c = c * 2;
    std::cout << "c new = " << c << std::endl;
    return 0;
}