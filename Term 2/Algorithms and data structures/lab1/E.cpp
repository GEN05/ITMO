#include <iostream>
#include <vector>

struct Matrix {
    int a1, a2, a3, a4;
};

Matrix multiplication(Matrix a, Matrix b, int module) {
    Matrix answer{};
    answer.a1 = (a.a1 * b.a1 + a.a2 * b.a3) % module;
    answer.a2 = (a.a1 * b.a2 + a.a2 * b.a4) % module;
    answer.a3 = (a.a3 * b.a1 + a.a4 * b.a3) % module;
    answer.a4 = (a.a3 * b.a2 + a.a4 * b.a4) % module;
    return answer;
}

void write(Matrix a) {
    std::cout << a.a1 << " " << a.a2 << '\n'
              << a.a3 << " " << a.a4 << '\n' << '\n';
}

int next_pow(int n) {
    int pow = 1;
    while (pow < n) {
        pow *= 2;
    }
    return pow;
}

std::vector<Matrix> build(std::vector<Matrix> a, int &k, int &module) {
    int n = a.size();
    std::vector<Matrix> t;
    t.resize(2 * k - 1);
    for (int i = 0; i < n; i++) {
        t[k - 1 + i] = a[i];
    }
    for (int i = k - 2; i >= 0; i--) {
        t[i] = multiplication(t[2 * i + 1], t[2 * i + 2], module);
    }
    return t;
}

Matrix sum(int v, int l, int r, int a, int b, std::vector<Matrix> &t, int &module) {
    Matrix null{};
    null.a1 = 1, null.a2 = 0, null.a3 = 0, null.a4 = 1;
    if ((l == r && l >= a && r <= b) || (a == l && b == r)) return t[v];
    if ((l > r) || (l > b || r < a) || l == r) return null;
    int m = (l + r) / 2;
    return multiplication(sum(2 * v + 1, l, m, a, std::min(b, m), t, module),
                          sum(2 * v + 2, m + 1, r, std::max(a, m + 1), b, t, module), module);
}

int main() {
    freopen("crypto.in", "r", stdin);
    freopen("crypto.out", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    int module, n, m;
    std::vector<Matrix> a;
    std::cin >> module >> n >> m;
    int k = next_pow(n);
    a.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].a1;
        std::cin >> a[i].a2;
        std::cin >> a[i].a3;
        std::cin >> a[i].a4;
    }
    std::vector<Matrix> t = build(a, k, module);
    int l, r;
    for (int i = 0; i < m; i++) {
        std::cin >> l >> r;
        write(sum(0, 0, k - 1, l - 1, r - 1, t, module));
    }
    return 0;
}