#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::vector<int>> a;
std::vector<int> temp;
int n, k, m, step, t, p;

int main() {
    freopen("telemetry.in", "r", stdin);
    freopen("telemetry.out", "w", stdout);
    std::cin >> n >> k;
    m = pow(k, n);
    a.resize(m);
    temp.resize(k);
    for (int i = 0; i < m; i++) {
        a[i].resize(n);
    }
    for (int i = 0; i < k; i++) {
        temp[i] = i;
    }
    step = 1;
    for (int i = 0; i < n; i++) {
        (i != 0) ? step *= k: step *= 1;
        t = 0;
        while (t < m) {
            p = 0;
            while (t < m && p < k) {
                for (int j = 0; j < step; j++) {
                    a[t][i] = temp[p];
                    t++;
                }
                p++;
            }
            p--;
            while (t < m && p > -1) {
                for (int j = 0; j < step; j++) {
                    a[t][i] = temp[p];
                    t++;
                }
                p--;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << a[i][j];
        }
        std::cout << std::endl;
    }
    return 0;
}