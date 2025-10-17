#include <iostream>
#include <fstream>

int main(void) {
    int input;
    std::ofstream outfile("q2_output.txt");
    outfile << "x" << " " << "x^2" << std::endl;

    std::cout << "Enter input integer" << std::endl;
    std::cin >> input;

    std::cout << "Multiples are:" << std::endl;
    if (input < 0) {
        std::cout << "Enter a positive integer" << std::endl;
        std::cin >> input;
        std::cout << "Multiples are:" << std::endl;
        for (int i = 0; i <= input; i++) {
            std::cout << i << " * " << i << " = " << i*i << std::endl;
            outfile << i << " " << i*i << std::endl;
        }
    }
    else {
        for (int i = 0; i <= input; i++) {
            std::cout << i << " * " << i << " = " << i*i << std::endl;
            outfile << i << " " << i*i << std::endl;
        }
    }
    outfile.close();
    std::cout << "Data written to output.txt" << std::endl;
    return 0;
}

// in terminal
// gnuplot
// plot "q2_output.txt" using 1:2 with linespoints