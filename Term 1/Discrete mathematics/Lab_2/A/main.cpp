#include <iostream>
#include <vector>
#include <algorithm>

int n;
long long ans = 0;
std::vector<long long> p;
std::vector<long long> q;

int main() {
    freopen("huffman.in", "r", stdin);
    freopen("huffman.out", "w", stdout);
    std::cin >> n;
    p.resize(n + 1);
    q.resize(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }
    p[n] = 999999999999999;
    std::sort(p.begin(), p.end());
    for (int i = 0; i < n + 1; i++) {
        q[i] = 999999999;
    }
    int i = 0, j = 0;
    for (int k = 0; k < n - 1; k++) {
        if (p[i] + p[i + 1] <= p[i] + q[j] && p[i] + p[i + 1] <= q[j] + q[j + 1]) {
            q[k] = p[i] + p[i + 1];
            ans += q[k];
            i += 2;
        } else if (p[i] + q[j] <= p[i] + p[i + 1] && p[i] + q[j] <= q[j] + q[j + 1]) {
            q[k] = p[i] + q[j];
            ans += q[k];
            i++;
            j++;
        } else if (q[j] + q[j + 1] <= p[i] + p[i + 1] && q[j] + q[j + 1] <= p[i] + q[j]) {
            q[k] = q[j] + q[j + 1];
            ans += q[k];
            j += 2;
        }
    }
    std::cout << ans;
    return 0;
}