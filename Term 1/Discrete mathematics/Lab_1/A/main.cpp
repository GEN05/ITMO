#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::vector<int>> a;
std::vector<bool> b;
int n, m, x, y, index;
bool forward, back;

void way_forward(int r) { // can i get not a from a
    if (r == index) {
        forward = true;
        return;
    }
    b[r] = true;
    for (int i = 0; i < n; i++) {
        if ((a[r][i] == 1) && !b[i]) {
            way_forward(i);
        }
    }
}

void way_back(int r) { // can i get a from not a
    if (r == index) {
        back = true;
        return;
    }
    b[r] = true;
    for (int i = 0; i < n; i++) {
        if ((a[r][i] == 1) && !b[i]) {
            way_back(i);
        }
    }
}

int main() {
    std::cin >> n >> m;
    n *= 2;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++) {
        a[i].resize(n);
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) { // fill in adjacency matrix
        std::cin >> x >> y;
        if ((x > 0) && (y > 0)) { // x or y <=> not x -> y & not y -> x
            a[n / 2 + (x - 1)][(y - 1)] = 1;
            a[n / 2 + (y - 1)][(x - 1)] = 1;
        }
        if ((x < 0) && (y > 0)) { // not x or y <=> x -> y & not y -> not x
            a[std::abs(x) - 1][(y - 1)] = 1;
            a[n / 2 + (y - 1)][n / 2 + std::abs(x) - 1] = 1;
        }
        if ((x > 0) && (y < 0)) { // x or not y <=> not x -> not y & y -> x
            a[n / 2 + (x - 1)][n / 2 + std::abs(y) - 1] = 1;
            a[std::abs(y) - 1][x - 1] = 1;
        }
        if ((x < 0) && (y < 0)) { // not x or not y <=> x -> not y & y -> not x
            a[std::abs(x) - 1][n / 2 + std::abs(y) - 1] = 1;
            a[std::abs(y) - 1][n / 2 + abs(x) - 1] = 1;
        }
    }
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }*/
    for (int i = 0; i < n / 2; i++) {
        forward = false, back = false;
        for (int j = 0; j < n; j++) {
            b[j] = false;
        }
        index = n / 2 + i;
        way_forward(i);
        for (int j = 0; j < n; j++) {
            b[j] = false;
        }
        index = i;
        way_back(i + n / 2);
        if (forward && back) {
            std::cout << "YES";
            return 0;
        }
    }
    std::cout << "NO";
    return 0;
}