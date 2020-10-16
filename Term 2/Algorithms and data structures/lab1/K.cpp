#include <iostream>
#include <vector>

int next_pow(int n) {
    int pow = 1;
    while (pow < n) {
        pow *= 2;
    }
    return pow;
}

void update(int i, int x, std::vector<int> &t, int &k) {
    t[k - 1 + i] = x;
    int j = k - 1 + i;
    while (j > 0) {
        j = (j - 1) / 2;
        t[j] = std::min(t[2 * j + 1], t[2 * j + 2]);
    }
}

std::vector<int> build(int &n, int &k) {
    std::vector<int> t;
    t.resize(2 * k - 1);
    for (int i = 0; i < n; i++) {
        t[k - 1 + i] = i;
    }
    for (int i = n; i < k; i++) {
        t[k - 1 + i] = n;
    }
    for (int i = k - 2; i >= 0; i--) {
        t[i] = std::min(t[2 * i + 1], t[2 * i + 2]);
    }
    return t;
}

int min(int v, int l, int r, int a, int b, std::vector<int> &t) {
    if (l >= a && r <= b) return t[v];
    if (l >= b || r <= a) return t.size();
    return std::min(min(2 * v + 1, l, (l + r) / 2, a, b, t), min(2 * v + 2, (l + r) / 2, r, a, b, t));
}

int main() {
    freopen("parking.in","r",stdin);
    freopen("parking.out","w",stdout);
    std::ios_base::sync_with_stdio(false);
    int n, m, x;
    std::string s;
    std::cin >> n >> m;
    int k = next_pow(n);
    std::vector<int> t = build(n, k);
    for (int i = 0; i < m; i++) {
        std::cin >> s >> x;
        if (s[1] == 'n') {
            int answer = min(0, 0, k, x - 1, k, t);
            if (answer >= n) {
                answer = min(0, 0, k, 0, k, t);
            }
            std::cout << answer + 1 << std::endl;
            update(answer, n, t, k);
        } else {
            update(x - 1, x - 1, t, k);
        }
    }

    return 0;
}