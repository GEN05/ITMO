#include <iostream>
#include <vector>
#include <ctime>

std::vector<std::vector<int>> a;
std::vector<int> current;
int n;

bool check(std::vector<int> b) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b) {
            return false;
        }
    }
    return true;
}

std::vector<int> plus1(std::vector<int> c) {
    for (int i = 1; i < c.size(); i++) {
        c[i - 1] = c[i];
    }
    c[c.size() - 1] = 1;
    return c;
}

std::vector<int> plus0(std::vector<int> d) {
    for (int i = 1; i < d.size(); i++) {
        d[i - 1] = d[i];
    }
    d[d.size() - 1] = 0;
    return d;
}

int main() {
    //freopen("chaincode.in", "r", stdin);
    //freopen("chaincode.out", "w", stdout);
    std::cin >> n;
    unsigned int start_time = clock();
    current.resize(n);
    for (int i = 0; i < n; i++) {
        current[i] = 0;
    }
    a.push_back(current);
    while (true) {
        if (check(plus1(current))) {
            current = plus1(current);
        } else if (check(plus0(current))) {
            current = plus0(current);
        } else {
            break;
        }
        a.push_back(current);
    }
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < n; j++) {
            std::cout << a[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << clock() - start_time;
    return 0;
}