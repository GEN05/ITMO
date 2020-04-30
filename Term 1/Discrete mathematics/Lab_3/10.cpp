#include <iostream>
#include <vector>

int n;
std::vector<int> a;

void nextPartition() {
    a[a.size() - 1]--;
    a[a.size() - 2]++;
    if (a[a.size() - 2] > a[a.size() - 1]) {
        a[a.size() - 2] += a[a.size() - 1];
        a.pop_back();
    } else {
        while (a[a.size() - 2] * 2 <= a[a.size() - 1]) {
            a.push_back(a[a.size() - 1] - a[a.size() - 2]);
            a[a.size() - 2] = a[a.size() - 3];
        }
    }
    for (int i = 0; i < a.size() - 1; i++) {
        std::cout << a[i] << "+";
    }
    std::cout << a[a.size() - 1];
    std::cout << "\n";
}

int main() {
    freopen("partition.in", "r", stdin);
    freopen("partition.out", "w", stdout);
    std::cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        a[i] = 1;
    }
    for (int i = 0; i < a.size() - 1; i++) {
        std::cout << a[i] << "+";
    }
    std::cout << a[a.size() - 1];
    std::cout << "\n";
    while (a[0] != n) {
        nextPartition();
    }
    return 0;
}
