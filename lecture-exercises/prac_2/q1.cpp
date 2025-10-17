#include <iostream>
#include <cmath>
#include <complex>

int main(void) {
    double a, b, c;

    std::cout << "Let's solve ax^2 + bx + c = 0" << std::endl;
    std::cout << "Enter value for a:" << std::endl;
    std::cin >> a;
    std::cout << "Enter value for b:" << std::endl;
    std::cin >> b;
    std::cout << "Enter value for c:" << std::endl;
    std::cin >> c;

    if ((a > -1e-6) && (a < 1e-6)) {    // a~0
        if ((b > -1e-6) && (b < 1e-6)) {    // b~0
            if ((c > -1e-6) && (c < 1e-6)) {    //c~0
                std::cout << "True for any x value" << std::endl;
            }
            else {
                std::cout << "No solution" << std::endl;
            }
        }
        else {
            std::cout << "x = " << -c/b << std::endl;
        }
    }
    else {
        double det = (b*b) - (4*a*c);

        if (det < -1e-6) {
            std::complex<double> sqrt_det = std::sqrt(std::complex<double>(det, 0.0));
            std::complex<double> x1 = (-b + sqrt_det) / (2*a);
            std::complex<double> x2 = (-b - sqrt_det) / (2*a);

            std::cout << "Complex solutions are " << std::endl;
            std::cout << "x1 = " << creal(x1) << " + " << cimag(x1) << "i" << std::endl;
            std::cout << "x2 = " << creal(x2) << " + " << cimag(x2) << "i" << std::endl;
        }
        else if ((det > -1e-6) && (det < 1e-6)) {   // det~0
            double x1 = -b / (2*a);
            std::cout << "There is one real solution: x = " << x1 << std::endl;
        }
        else {
            double x1 = (-b + std::sqrt(det)) / (2*a);
            double x2 = (-b - std::sqrt(det)) / (2*a);
            std::cout << "Real solutions:" << std::endl;
            std::cout << "x1 = " << x1 << std::endl;
            std::cout << "x2 = " << x2 << std::endl;
        }
    }
    return 0;
}