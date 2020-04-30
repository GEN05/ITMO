#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::vector<int>> a;
std::vector<int> temp;
int n, m, j = 0;

void func(int k, int len) {
    if (k < len) {
        temp[k] = 0;
        func(k + 1, len);
        temp[k] = 1;
        func(k + 1, len);
    } else {
        for (int i = 0; i < len; i++) {
            a[j][i] = temp[i];
            if (i > 0 && a[j][i] == 1 && a[j][i - 1] == 1 && a[j][n] == 0) {
                m--;
                a[j][n] = 1;
            }
        }
        j++;
    }
}

int main() {
    freopen("vectors.in", "r", stdin);
    freopen("vectors.out", "w", stdout);
    std::cin >> n;
    m = pow(2, n);
    a.resize(m);
    temp.resize(n);
    for (int i = 0; i < m; i++) {
        a[i].resize(n + 1);
    }
    func(0, n);
    std::cout << m << std::endl;
    for (int i = 0; i < a.size(); i++) {
        if (a[i][n] == 0) {
            for (int j = 0; j < a[i].size() - 1; j++) {
                std::cout << a[i][j];
            }
            std::cout << std::endl;
        }
    }
    return 0;
}