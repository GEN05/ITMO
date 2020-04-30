#include <iostream>
#include <vector>

std::vector<int> choose;
std::vector<std::vector<long long>> c;
int n, k, next;
long long m;

long long funcChoose(int up, int down) {
    long long sum = 1;
    for (int i = 1; i <= up - down; i++) {
        sum = sum * (down + i) / i;
    }
    return sum;
}

int main() {
    freopen("num2choose.in", "r", stdin);
    freopen("num2choose.out", "w", stdout);
    std::cin >> n >> k >> m;
    //std::cout << funcChoose(n, k) << " j\n";
    next = 1;
    while (k > 0) {
        if (m < funcChoose(n - 1, k - 1)) {
            choose.push_back(next);
            k--;

        } else {
            m -= funcChoose(n - 1, k - 1);
        }
        n--;
        next++;
    }
    for (int i : choose) {
        std::cout << i << " ";
    }
    return 0;
}
