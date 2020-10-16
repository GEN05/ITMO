#include <iostream>
#include <vector>
#include <cmath>

struct tree {
    std::vector<std::vector<int>> vector;
    std::vector<int> depth;
    int m;

    explicit tree(int n) {
        m = (int) (log(n) / log(2)) + 1;
        vector.resize(n);
        depth.resize(n);
        for (auto &i : vector)
            i.resize(m);
        depth[1] = 1;
        for (int i = 2; i < n; i++) {
            std::cin >> vector[i][0];
            depth[i] = depth[vector[i][0]] + 1;
        }
    }
};

int lca(tree *a, int u, int v) {
    if (a->depth[u] > a->depth[v])
        std::swap(u, v);
    for (int i = a->m; i >= 0; i--)
        if (a->depth[a->vector[v][i]] - a->depth[u] >= 0)
            v = a->vector[v][i];
    if (u == v)
        return u;
    for (int i = a->m; i >= 0; i--) {
        if (a->vector[u][i] != a->vector[v][i]) {
            u = a->vector[u][i];
            v = a->vector[v][i];
        }
    }
    return a->vector[u][0];
}

int main() {
    int n, m, u, v;
    std::cin >> n;
    tree *a = new tree(++n);
    for (int j = 1; j < a->m; j++)
        for (int i = 0; i < n; i++)
            a->vector[i][j] = a->vector[a->vector[i][j - 1]][j - 1];
    std::cin >> m;
    a->m--;
    for (int i = 0; i < m; i++) {
        std::cin >> u >> v;
        std::cout << lca(a, u, v) << std::endl;
    }
    return 0;
}