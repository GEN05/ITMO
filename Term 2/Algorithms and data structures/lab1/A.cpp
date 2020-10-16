#include <iostream>
#include <vector>

typedef long long ll;

int main() {
    int n, x, y, m;
    ll answer;
    std::vector<ll> sum;
    std::vector<int> a;
    std::cin >> n;
    a.resize(n), sum.resize(n);
    std::cin >> x >> y >> a[0];
    a[0] %= 1 << 16;
    sum[0] = a[0];
    for (int i = 1; i < n; i++) {
        a[i] = ((unsigned long long) x * a[i - 1] + y) % (1 << 16);
        sum[i] = sum[i - 1] + a[i];
    }
    std::cin >> m;
    if (m == 0) {
        std::cout << 0 << "\n";
        return 0;
    }
    a.resize(2 * m);
    std::cin >> x >> y >> a[0];
    //a[0] %= 1 << 16;
    for (int i = 1; i < 2 * m; i++) {
        a[i] = ((unsigned long long) x * a[i - 1] + y + (1 << 30)) % (1 << 30);
    }
    for (int &i : a) {
        i %= n;
    }
    answer = 0;
    for (int i = 0; i < m; i++) {
        x = std::max(a[2 * i], a[2 * i + 1]);
        y = std::min(a[2 * i], a[2 * i + 1]);
        answer += sum[x];
        if (y > 0) answer -= sum[y - 1];
    }
    std::cout << answer;
    return 0;
}