#include <iostream>
#include <cmath>

double t(double x, int v1, int v2, double a) {
    return ((sqrt(x * x + (1 - a) * (1 - a))) / v1 + (sqrt(a * a + (1 - x) * (1 - x))) / v2);
}

int main() {
    int v1, v2;
    double l = 0, r = 1, eps = 1e-10, f, g, a;
    std::cin >> v1 >> v2 >> a;
    while (r - l >= eps) {
        f = l + (r - l) / 3;
        g = r - (r - l) / 3;
        if (t(f, v1, v2, a) < t(g, v1, v2, a)) {
            r = g;
        } else {
            l = f;
        }
    }
    std::cout << std::fixed;
    std::cout.precision(7);
    std::cout << l;
    return 0;
}