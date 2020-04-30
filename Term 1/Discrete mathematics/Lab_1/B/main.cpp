#include <iostream>
#include <vector>

std::vector<std::vector<int>> a;
std::vector<int> col;
int n, k, i, j, temp, index;

int main() {
    std::cin >> n >> k;
    a.resize(k);
    col.resize(k);
    for (i = 0; i < k; i++) {
        a[i].resize(n);
        for (j = 0; j < n; j++) {
            std::cin >> a[i][j];
            if (a[i][j] != -1) {
                col[i]++;
            }
        }
    }

    while (true) {
        i = 0;
        while (i != k && col[i] != 1) {
            i++;
        }
        if (i == k) {
            std::cout << "NO";
            return 0;
        }
        for (j = 0; j < n; j++) {
            if (a[i][j] != -1) {
                col[i]--;
                temp = a[i][j];
                index = j;
                a[i][j] = -1;
            }
        }
        for (j = 0; j < k; j++) {
            if (a[j][index] == temp) {
                col[j] = 0;
            } else if (a[j][index] != -1 && a[j][index] != temp) {
                if (col[j] == 1) {
                    std::cout << "YES";
                    return 0;
                } else {
                    a[j][index] = -1;
                    col[j]--;
                }
            }
        }
    }
}