#include <iostream>
#include <vector>
#include <cmath>

#define INF 1e7 + 1

struct tree {
    std::vector<std::vector<int>> vector;
    std::vector<int> depth;
    std::vector<std::vector<int>> min;
    int m;

    explicit tree(int n) {
        m = (int) (log(n) / log(2)) + 1;
        vector.resize(n);
        depth.resize(n);
        min.resize(n);
        for (auto &i : vector)
            i.resize(m);
        for (auto &i : min)
            i.resize(m);
        min[0][0] = min[1][0] = INF;
        depth[1] = 1;
        for (int i = 2, temp; i < n; i++) {
            std::cin >> vector[i][0] >> temp;
            depth[i] = depth[vector[i][0]] + 1;
            min[i][0] = temp;
        }
    }
};

int lca(tree *a, int u, int v) {
    if (a->depth[u] > a->depth[v])
        std::swap(u, v);
    int result = INF;
    for (int i = a->m; i >= 0; i--)
        if (a->depth[a->vector[v][i]] - a->depth[u] >= 0) {
            result = std::min(result, a->min[v][i]);
            v = a->vector[v][i];
        }
    if (u == v)
        return result;
    for (int i = a->m; i >= 0; i--) {
        if (a->vector[u][i] != a->vector[v][i]) {
            result = std::min(result, std::min(a->min[u][i], a->min[v][i]));
            u = a->vector[u][i];
            v = a->vector[v][i];
        }
    }
    return std::min(result, std::min(a->min[u][0], a->min[v][0]));
}

int main() {
    freopen("minonpath.in", "r", stdin);
    freopen("minonpath.out", "w", stdout);
    int n, m, u, v;
    std::cin >> n;
    tree *a = new tree(++n);
    for (int j = 1; j < a->m; j++)
        for (int i = 0; i < n; i++) {
            a->vector[i][j] = a->vector[a->vector[i][j - 1]][j - 1];
            a->min[i][j] = std::min(a->min[i][j - 1], a->min[a->vector[i][j - 1]][j - 1]);
        }
    std::cin >> m;
    a->m--;
    for (int i = 0; i < m; i++) {
        std::cin >> u >> v;
        std::cout << lca(a, u, v) << '\n';
    }
    return 0;
}