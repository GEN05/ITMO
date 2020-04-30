#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::vector<int>> a;
int n, k, step = 1, t, i, j;

int main() {
    //freopen("gray.in", "r", stdin);
    //freopen("gray.out", "w", stdout);
    std::cin >> n;
    k = pow(2.0, n);
    a.resize(k);
    for (i = 0; i < k; i++) {
        a[i].resize(n);
    }
    a[0][n - 1] = 0;
    a[1][n - 1] = 1;
    for (i = 1; i < n; i++) {
        step *= 2;
        t = step - 1;
        for (j = step; j < step * 2; j++) {
            a[j] = a[t];
            a[t][n - i - 1] = 0;
            a[j][n - i - 1] = 1;
            t--;
        }
    }

    for (i = 0; i < k; i++) {
        for (j = 0; j < n; j++) {
            std::cout << a[i][j];
        }
        std::cout << std::endl;
    }
}