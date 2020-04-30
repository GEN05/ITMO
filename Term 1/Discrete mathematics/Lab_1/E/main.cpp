#include <iostream>
#include <vector>
#include <cmath>

int n, step, ans, temp, buf, max, kol, answer;
std::vector<std::vector<int>> a;
std::vector<std::vector<int>> b;
std::vector<int> c, notc;
std::vector<int> value;
std::vector<int> d;
std::vector<int> f;

int next() {
    for (int i = 0; i < notc.size(); i++) {
        step = 0, ans = 0;
        for (int j = b[notc[i]].size() - 1; j >= 0; j--) {
            ans += value[b[notc[i]][j]] * f[step];
            step++;
        }
        value[notc[i]] = a[notc[i]][ans];
    }
}

bool func(int k, int len) {
    if (k < len) {
        value[c[k]] = false;
        func(k + 1, len);
        value[c[k]] = true;
        func(k + 1, len);
    } else {
        next();
        std::cout << value[value.size() - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> n;
    f.resize(10);
    for (int i = 0; i < 10; i++) {
        f[i] = int(pow(2.0, i));
    }
    if (n == 0) {
        std::cout << "0";
    } else {
        d.resize(n);
        b.resize(n);
        a.resize(n);
        for (int i = 0; i < n; i++) {
            std::cin >> temp;
            a[i].resize(int(pow(2.0, temp)));
            if (temp == 0) {
                b[i].push_back(0);
                d[i] = 0;
                c.push_back(i);
            } else {
                notc.push_back(i);
                max = -1;
                for (int j = 0; j < temp; j++) {
                    std::cin >> buf;
                    b[i].push_back(buf - 1);
                    if (d[buf - 1] > max) {
                        max = d[buf - 1];
                    }
                }
                d[i] = max + 1;
            }
            if (temp != 0) {
                for (int j = 0; j < int(pow(2.0, temp)); j++) {
                    std::cin >> a[i][j];
                }
            }
        }
        value.resize(n);
        answer = d[0];
        kol = c.size();
        for (int i = 1; i < d.size(); i++) {
            if (d[i] > answer) {
                answer = d[i];
            }
        }
        std::cout << answer << std::endl;
        func(0, kol);
    }
}