#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> a;
int n;
int temp = 0;

int antiGray(int k, int size) {
    if (size < n) {
        a[k] = 0;
        antiGray(k + 1, size + 1);
        a[k] = 1;
        antiGray(k + 1, size + 1);
        a[k] = 2;
        antiGray(k + 1, size + 1);
    } else if (temp < pow(3, n - 1)) {
        temp++;
        for (int i = 0; i < size; i++) std::cout << a[i];
        std::cout << std::endl;
        for (int i = 0; i < size; i++) std::cout << (a[i] + 1) % 3;
        std::cout << std::endl;
        for (int i = 0; i < size; i++) std::cout << (a[i] + 2) % 3;
        std::cout << std::endl;
    }
    return 0;
}

int main() {
    freopen("antigray.in", "r", stdin);
    freopen("antigray.out", "w", stdout);
    std::cin >> n;
    a.resize(n);
    antiGray(0, 0);
}