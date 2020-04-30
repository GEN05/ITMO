#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::vector<int>> a;
std::vector<std::vector<int>> b;
std::vector<std::vector<int>> c;
int n, check = 0, temp, flag, sum, p;
std::string s;

int mon(int t, int l, int r, int len) {
    if (len > 0) {
        for (int i = l; i < r; i++) {
            if (a[t][i] > a[t][i + len]) check++;
        }
        mon(t, l, (r - l) / 2, (r - l) / 2);
        mon(t, r, r + len / 2, (r - l) / 2);
    }
    return check;
}

int main() {
    std::cin >> n;
    c.resize(5);
    a.resize(n);
    for (int i = 0; i < 5; i++) {
        c[i].resize(n);
    }
    for (int i = 0; i < n; i++) {
        std::cin >> temp >> s;
        a[i].resize(int(pow(2.0, temp)));
        for (int j = 0; j < int(pow(2.0, temp)); j++) {
            if (s[j] == '1') {
                a[i][j] = 1;
            } else {
                a[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if ((a[i].size() == 1) && (a[i][0] == 0)) {
            c[0][i] = 1;
            c[1][i] = 0;
            c[2][i] = 0;
            c[3][i] = 1;
            c[4][i] = 1;
        } else if (a[i].size() == 1 && a[i][0] == 1) {
            c[0][i] = 0;
            c[1][i] = 1;
            c[2][i] = 0;
            c[3][i] = 1;
            c[4][i] = 1;

        } else {
            flag = 0;
            check = 0;
            if (a[i][0] == 0) {
                c[0][i] = 1;
            }
            if (a[i][a[i].size() - 1] == 1) {
                c[1][i] = 1;
            }
            for (int j = 0; j < a[i].size() / 2; j++) {
                if (a[i][j] != a[i][a[i].size() - 1 - j]) {
                    flag++;
                }
            }
            if (flag != a[i].size() / 2) {
                c[2][i] = 0;
            } else {
                c[2][i] = 1;
            }
            if (mon(i, 0, (a[i].size()) / 2, a[i].size() / 2) != 0) {
                c[3][i] = 0;
            } else c[3][i] = 1;
            b.resize(a[i].size());
            for (int j = 0; j < b.size(); j++) {
                b[j].resize(a[i].size());
            }
            for (int j = 0; j < b.size(); j++) {
                b[j][0] = a[i][j];
            }

            for (int j = 1; j < b.size(); j++) {
                for (int k = 0; k < b.size() - j; k++) {
                    b[k][j] = (b[k][j - 1] + b[k + 1][j - 1]) % 2;
                }
            }

            c[4][i] = 1;
            p = 0;
            for (int j = 1; j < b.size(); j++) {
                if (j != int(pow(2.0, p))) {
                    if (b[0][j] == 1) {
                        c[4][i] = 0;
                    }
                } else {
                    p++;
                }
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        sum = 0;
        for (int j = 0; j < n; j++) {
            sum += c[i][j];
        }
        if (sum == c[i].size()) {
            std::cout << "NO";
            return 0;
        }
    }
    std::cout << "YES";
    return 0;
}