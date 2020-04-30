#include <iostream>
#include <cmath>

int n, k;

int main() {
    freopen("allvectors.in", "r", stdin);
    freopen("allvectors.out", "w", stdout);
    std::cin >> n;
    for (int i = 0; i < pow(2.0, n); i++) {
        k = std::pow(2.0, n - 1);
        while (k > 0) { //
            std::cout << bool(i & k);
            k = k >> 1;
        };
        std::cout << std::endl;
    }

    return 0;
}