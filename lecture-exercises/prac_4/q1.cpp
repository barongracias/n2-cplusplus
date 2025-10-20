#include <iostream>
#include <cmath>
using namespace std;

double sum(int a, int b) {
    return a + b;
}

void decrease(int &a, int b) {
    a = a - b;
}

double q(double a, double b, double c, double &x1, double &x2) {
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        // no real roots
        return 0;
    } 
    else if (discriminant == 0) {
        // one real root
        x1 = -b / (2 * a);
        x2 = x1;
        return 1;
    } 
    else {
        // two real roots
        double sqrtD = sqrt(discriminant);
        x1 = (-b + sqrtD) / (2 * a);
        x2 = (-b - sqrtD) / (2 * a);
        return 2;
    }
}

int main(void) {
    int x = 5;
    int y = 2;
    double a=1, b=-2, c=-5;
    double x1, x2;
    int sols = q(a, b, c, x1, x2);

    cout << sols << endl;

    // cout << sum(x, y) << endl;
    // decrease(x, y);
    // cout << x << endl;



    return 0;
}