#include <iostream>
#include <vector>

int n, min, m, v;
std::vector<std::vector<int>> a;

std::vector<int> reverse(std::vector<int> c, int front, int back) {
    while ((front != back) && (front != --back)) std::swap(c[front++], c[back]);
    return c;
}

std::vector<int> nextPermutation(std::vector<int> b) {
    for (int i = n - 2; i >= 0; i--) {
        if (b[i] < b[i + 1]) {
            min = i + 1;
            for (int j = i + 1; j < n; j++) if (b[j] < b[min] && b[j] > b[i]) min = j;
            std::swap(b[i], b[min]);
            b = reverse(b, i + 1, n);
            break;
        }
    }
    return b;
}

int factorial(int k) {
    int sum = 1;
    for (int i = 1; i <= k; i++) sum *= i;
    return sum;
}

int main() {
    freopen("permutations.in", "r", stdin);
    freopen("permutations.out", "w", stdout);
    std::cin >> n;
    m = factorial(n);
    a.resize(m);
    for (int i = 0; i < m; i++) a[i].resize(n);
    for (int i = 0; i < n; i++) a[0][i] = i + 1;
    for (int i = 0; i < m - 1; i++) a[i + 1] = nextPermutation(a[i]);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) std::cout << a[i][j] << " ";
        std::cout << std::endl;
    }
    return 0;
}