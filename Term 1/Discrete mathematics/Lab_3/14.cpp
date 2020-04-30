#include <iostream>
#include <vector>

std::vector<int> a;
std::vector<long long> p;
std::vector<bool> was;
int n;
long long numOfPermutation;

long long factorial(int r) {
    long long sum = 1;
    for (int i = 1; i <= r; i++) sum *= i;
    return sum;
}

int main() {
    freopen("perm2num.in", "r", stdin);
    freopen("perm2num.out", "w", stdout);
    std::cin >> n;
    a.resize(n + 1), was.resize(n + 1), p.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        p[i] = factorial(i);
    }
    numOfPermutation = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= a[i] - 1; j++) {
            if (was[j] == false) {
                numOfPermutation += p[n - i];
            }
        }
        was[a[i]] = true;
    }
    std::cout << numOfPermutation;
    return 0;
}
