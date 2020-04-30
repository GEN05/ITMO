#include <iostream>
#include <cmath>

long double f(long double x) {
    return x * x + sqrt(x);
}

int main() {
    long double c, l = 0, r = 1e15, m, eps = 1e-10;
    std::cin >> c;
    while (fabs(r - l) > eps) {
        m = (r + l) / 2.0;
        if (f(m) - c < 0) {
            l = m;
        } else {
            r = m;
        }
    }
    std::cout << std::fixed;
    std::cout.precision(7);
    std::cout << r;
    return 0;
}