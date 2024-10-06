#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// Time limits in microseconds
const double SECOND = 1e6;
const double MINUTE = 60 * SECOND;
const double HOUR = 60 * MINUTE;
const double DAY = 24 * HOUR;
const double MONTH = 30 * DAY;
const double YEAR = 365 * DAY;
const double CENTURY = 100 * YEAR;

// Functions to calculate the largest n
double logn(double time) {
    return log2(time); // Corrected: n = log2(time) for lg n
}

double sqrt_n(double time) {
    return pow(time, 0.5); // n = sqrt(time), corrected to use proper power
}

double linear_n(double time) {
    return time; // n = time for linear time
}

double nlogn(double time) {
    double n = 2;
    while (n * log2(n) <= time) {
        n++;
    }
    return n - 1;
}

double n_squared(double time) {
    return sqrt(time); // n^2 = t, so n = sqrt(t)
}

double n_cubed(double time) {
    return cbrt(time); // n^3 = t, so n = cbrt(t)
}

double two_power_n(double time) {
    return log2(time); // 2^n = t, so n = log2(t)
}

double factorial_n(double time) {
    int n = 1;
    double fact = 1;
    while (fact <= time) {
        n++;
        fact *= n;
    }
    return n - 1;
}

void print_results(double time, const string& label) {
    cout << label << " (" << time << " microseconds):\n";
    cout << "lg n: " << logn(time) << "\n";
    cout << "sqrt(n): " << sqrt_n(time) << "\n";
    cout << "n: " << linear_n(time) << "\n";
    cout << "n lg n: " << nlogn(time) << "\n";
    cout << "n^2: " << n_squared(time) << "\n";
    cout << "n^3: " << n_cubed(time) << "\n";
    cout << "2^n: " << two_power_n(time) << "\n";
    cout << "n!: " << factorial_n(time) << "\n";
    cout << "------------------------------\n";
}

int main() {
    // Time limits to test
    print_results(SECOND, "1 second");
    print_results(MINUTE, "1 minute");
    print_results(HOUR, "1 hour");
    print_results(DAY, "1 day");
    print_results(MONTH, "1 month");
    print_results(YEAR, "1 year");
    print_results(CENTURY, "1 century");

    return 0;
}
