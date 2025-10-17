#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double y, double t) {
    return sqrt(y);
}

int main(void) {
    ofstream outfile("prac3_q1_output.txt");

    double T;
    double y0;
    double dt;

    cout << "Enter value for T" << endl;
    cin >> T;
    cout << "Enter value for y0" << endl;
    cin >> y0;
    cout << "Enter value for dt" << endl;
    cin >> dt;

    double t = 0.0;
    double y = y0;
    int N = static_cast<int>(T / dt);
    
    outfile << "# t y " << endl;

    while (t < T) {
        outfile << fixed << setprecision(6) << t << " " << y << endl;

        if (t + dt > T) {
            dt = T - t;
        }
        y = y + dt * f(y, t);
        t = t + dt;
    }

    outfile.close();
    cout << "Data written to prac3_q1_output.txt" << endl;
    return 0;
}