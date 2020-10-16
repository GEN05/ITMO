#include <iostream>
#include <vector>

typedef long long ll;

ll pow(ll x) {
    return 1ull << x;
}

int main() {
    ll const module = 16714589, digit = 21563;
    ll n, m, u, v, temp_u, temp_v, delta, answer;
    std::vector<ll> a(100001);
    std::vector<std::vector<ll>> spare_table(18); // 1 << 18 > 1e5
    for (auto &i : spare_table)
        i.resize(100001);
    std::cin >> n >> m >> spare_table[0][1];
    for (int i = 2; i <= n; i++) {
        spare_table[0][i] = (23 * spare_table[0][i - 1] + digit) % module;
        a[i] = i % pow(a[i - 1]) != 0 ? a[i - 1] : a[i - 1] + 1;
    }
    for (int i = 1; i < spare_table.size(); i++)
        for (int j = 1; j <= (n - pow(i) + 1); j++)
            spare_table[i][j] = std::min(spare_table[i - 1][j], spare_table[i - 1][j + pow(i - 1)]);
    std::cin >> u >> v;
    temp_u = u, temp_v = v;
    if (temp_u < temp_v) std::swap(temp_u, temp_v);
    delta = std::abs(++temp_u - temp_v);
    answer = std::min(spare_table[a[delta]][temp_v], spare_table[a[delta]][temp_u - pow(a[delta])]);
    ll i = 1;
    while (i < m) {
        u = ((17 * u + 751 + answer + 2 * i) % n) + 1;
        v = ((13 * v + 593 + answer + 5 * i) % n) + 1;
        temp_u = u;
        temp_v = v;
        if (temp_u < temp_v) std::swap(temp_u, temp_v);
        delta = std::abs(++temp_u - temp_v);
        answer = std::min(spare_table[a[delta]][temp_v], spare_table[a[delta]][temp_u - pow(a[delta])]);
        i++;
    }
    std::cout << u << " " << v << " " << answer;
    return 0;
}