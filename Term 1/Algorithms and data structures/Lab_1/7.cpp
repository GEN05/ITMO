#include <iostream>
#include <algorithm>

int main() {
    long long n, x, y;
    std::cin >> n >> x >> y;
    n--;
    long long m, l = 0, r = n * __max(x, y);
    while (r > l) {
        m = l + (r - l) / 2;
        if ((m / x + m / y) < n) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    std::cout << r + __min(x, y);
    return 0;
}