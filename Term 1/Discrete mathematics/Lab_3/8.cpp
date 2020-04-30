#include <iostream>
#include <vector>

int n, k;
std::vector<std::vector<int>> a;
std::vector<int> d;
long long m;

std::vector<int> nextChoose(std::vector<int> b) {
    d.resize(m);
    for (int i = 0; i < k; i++) d[i] = b[i];
    d[k] = n + 1;
    int i = k - 1;
    while (i >= 0 && d[i + 1] - d[i] < 2) i--;
    if (i >= 0) {
        d[i]++;
        for (int j = i + 1; j < k; j++) d[j] = d[j - 1] + 1;;
        for (int l = 0; l < k; l++) b[l] = d[l];
        return b;
    }
}

long long factorial(int p) {
    long long sum = 1;
    for (int i = 1; i <= p; i++) sum *= i;
    return sum;
}

int main() {
    //freopen("choose.in", "r", stdin);
    //freopen("choose.out", "w", stdout);
    std::cin >> n >> k;
    m = factorial(n) / (factorial(k) * factorial(n - k));
    a.resize(m);
    for (int i = 0; i < m; i++) a[i].resize(k);
    for (int i = 0; i < k; i++) a[0][i] = i + 1;
    for (int i = 0; i < m - 1; i++) a[i + 1] = nextChoose(a[i]);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) std::cout << a[i][j] << " ";
        std::cout << std::endl;
    }
    return 0;
}