#include <iostream>
#include <cmath>
#include <vector>

std::vector<std::string> a;
std::vector<std::vector<int>> b;

int main() {
    int n, m;
    std::cin >> n;
    m = pow(2.0, n);
    a.resize(m), b.resize(m);
    for (int i = 0; i < m; i++) {
        b[i].resize(m);
        std::cin >> a[i] >> b[i][0];
    }
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < m - i; j++) {
            b[j][i] = (b[j][i - 1] + b[j + 1][i - 1]) % 2;
        }
    }
    for (int i = 0; i < m; i++) {
        std::cout << a[i] << " " << b[0][i] << std::endl;
    }
    return 0;
}