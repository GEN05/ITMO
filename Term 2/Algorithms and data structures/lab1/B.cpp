#include <iostream>
#include <vector>

long long next_pow(long long n) {
    long long pow = 1;
    while (pow < n) {
        pow *= 2;
    }
    return pow;
}

void update(long long i, long long x, std::vector<long long> &t, long long &k) {
    t[k - 1 + i] = x;
    long long j = k - 1 + i;
    while (j > 0) {
        j = (j - 1) / 2;
        t[j] = t[2 * j + 1] + t[2 * j + 2];
    }
}

std::vector<long long> build(std::vector<long long> a, long long &k) {
    long long n = a.size();
    std::vector<long long> t;
    t.resize(2 * k - 1);
    for (long long i = 0; i < n; i++) {
        t[k - 1 + i] = a[i];
    }
    for (long long i = n; i < k; i++) {
        t[k - 1 + i] = 0;
    }
    for (long long i = k - 2; i >= 0; i--) {
        t[i] = t[2 * i + 1] + t[2 * i + 2];
    }
    return t;
}

long long sum(long long v, long long l, long long r, long long a, long long b, std::vector<long long> &t) {
    if (l >= a && r <= b) return t[v];
    if (l >= b || r <= a) return 0;
    return sum(2 * v + 1, l, (l + r) / 2, a, b, t) + sum(2 * v + 2, (l + r) / 2, r, a, b, t);
}

int main() {
    long long n;
    std::string s;
    std::vector<long long> a;
    std::cin >> n;
    long long k = next_pow(n);
    a.resize(n);
    for (long long i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<long long> t = build(a, k);
    int y = 11;
    int l, r;
    while (std::cin >> s) {
        std::cin >> l >> r;
        if (s[1] == 'u') {
            std::cout << sum(0, 0, k, l - 1, r, t) << '\n';
        }
        if (s[1] == 'e') {
            update(l - 1, r, t, k);
        }
        y--;
    }
    return 0;
}