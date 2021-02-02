#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

struct Edge {
    int from;
    int to;
    long long weight;
    int index;

    bool operator<(const Edge &rhs) const {
        if (weight < rhs.weight)
            return true;
        if (rhs.weight < weight)
            return false;
        if (index < rhs.index)
            return true;
        if (rhs.index < index)
            return false;
        if (from < rhs.from)
            return true;
        if (rhs.from < from)
            return false;
        return to < rhs.to;
    }

    bool operator>(const Edge &rhs) const {
        return rhs < *this;
    }
};

static int find(int from, std::vector<int> &p) {
    if (p[from] != from) {
        p[from] = find(p[from], p);
        return p[from];
    }
    return from;
}

static void join(int from, int to, std::vector<int> &p) {
    from = find(from, p);
    to = find(to, p);
    p[to] = from;
}

int main() {
    freopen("destroy.in", "r", stdin);
    freopen("destroy.out", "w", stdout);
    int n, m;
    long long sum;
    std::cin >> n >> m >> sum;
    std::vector<Edge> graph;
    for (int i = 0; i < m; i++) {
        int from, to;
        long long weight;
        std::cin >> from >> to >> weight;
        graph.push_back({from - 1, to - 1, -weight, i + 1});
    }
    std::sort(graph.begin(), graph.end());
    std::vector<int> p;
    std::vector<int> mst;
    p.reserve(n);
    for (int i = 0; i < n; i++)
        p.push_back(i);
    long long ans = 0;
    for (auto &edge : graph) {
        int from = edge.from;
        int to = edge.to;
        long long weight = edge.weight;
        int index = edge.index;
        if (find(from, p) == find(to, p))
            continue;
        ans += weight;
        mst.push_back(index);
        join(from, to, p);
    }
    for (auto &i : graph)
        i.weight *= -1;
    std::sort(graph.begin(), graph.end());
    std::set<int> answer;
    for (auto &i : graph) {
        auto it = std::find(mst.begin(), mst.end(), i.index);
        if (it != mst.end())
            continue;
        if (sum - i.weight >= 0) {
            answer.insert(i.index);
            sum -= i.weight;
        } else break;
    }
    int size = answer.size();
    std::cout << size << '\n';
    for (auto &i : answer)
        std::cout << i << ' ';
    return 0;
}
