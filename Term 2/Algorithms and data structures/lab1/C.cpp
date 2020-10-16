#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

struct Node {
    int left;
    int right;
    ll val;
    ll set;
    ll add;
    bool real;
    bool isSet;
};

int treeSize;
Node *tree;

ll next_pow(ll n) {
    ll pow = 1;
    while (pow < n) {
        pow <<= 1;
    }
    return pow;
}

void build(std::vector<ll> &a, int sizeA) {
    treeSize = next_pow(sizeA);
    tree = new Node[treeSize * 2 - 1];
    for (int i = 0; i < treeSize * 2 - 1; i++)
        tree[i] = {0, 0, 0, 0, false, false};
    for (int i = 0; i < sizeA; i++) {
        tree[treeSize - 1 + i].val = a[i];
        tree[treeSize - 1 + i].real = true;
    }
    for (int i = 0; i < treeSize; i++) {
        tree[treeSize - 1 + i].left = i;
        tree[treeSize - 1 + i].right = i + 1;
    }
    for (int i = treeSize - 2; 0 <= i; i--) {
        tree[i].real = tree[i * 2 + 1].real || tree[i * 2 + 2].real;
        tree[i].val = !tree[i * 2 + 1].real || !tree[i * 2 + 2].real ? !tree[i * 2 + 1].real ? !tree[i * 2 + 2].real ? 0
                                                                                                                     : tree[
                                                                                                       i * 2 + 2].val
                                                                                             : tree[i * 2 + 1].val
                                                                     : std::min(tree[i * 2 + 1].val,
                                                                                tree[i * 2 + 2].val);
        tree[i].left = tree[i * 2 + 1].left;
        tree[i].right = tree[i * 2 + 2].right;
    }
}

void push(int node) {
    if (tree[node].isSet) {
        tree[node].isSet = false;
        tree[node * 2 + 1].isSet = tree[node * 2 + 2].isSet = true;
        tree[node * 2 + 1].val = tree[node * 2 + 2].val = tree[node].set;
        tree[node * 2 + 1].set = tree[node * 2 + 2].set = tree[node].set;
        tree[node * 2 + 1].add = tree[node * 2 + 2].add = 0;
    }
    tree[node * 2 + 1].add += tree[node].add;
    tree[node * 2 + 2].add += tree[node].add;
    tree[node * 2 + 1].val += tree[node].add;
    tree[node * 2 + 2].val += tree[node].add;
    tree[node].add = 0;
}

void set(int node, int a, int b, ll x) {
    if (a <= tree[node].left && tree[node].right <= b) {
        tree[node].set = tree[node].val = x;
        tree[node].isSet = true;
        tree[node].add = 0;
    } else if (tree[node].right <= a || b <= tree[node].left) {
        return;
    } else {
        push(node);
        set(node * 2 + 1, a, b, x);
        set(node * 2 + 2, a, b, x);
        tree[node].val = std::min(tree[node * 2 + 1].val, tree[node * 2 + 2].val);
    }
}

void add(int node, int a, int b, ll x) {
    if (a <= tree[node].left && tree[node].right <= b) {
        tree[node].add += x;
        tree[node].val += x;
    } else if (tree[node].right <= a || b <= tree[node].left) {
        return;
    } else {
        push(node);
        add(node * 2 + 1, a, b, x);
        add(node * 2 + 2, a, b, x);
        tree[node].val = std::min(tree[node * 2 + 1].val, tree[node * 2 + 2].val);
    }
}

ll min(int i, int a, int b) {
    if (a <= tree[i].left && tree[i].right <= b) {
        return tree[i].val;
    } else if (tree[i].right < a || b < tree[i].left) {
        return 0;
    } else {
        push(i);
        std::vector<ll> pool;
        ll minimum = LONG_LONG_MAX;
        if (!(b <= tree[i].left || (tree[i].left + tree[i].right) / 2 <= a)) pool.push_back(min(i * 2 + 1, a, b));
        if (!(b <= (tree[i].left + tree[i].right) / 2 || tree[i].right <= a)) pool.push_back(min(i * 2 + 2, a, b));
        for (long long j : pool)
            if (j < minimum)
                minimum = j;
        return minimum;
    }
}

int main() {
    int n, i, j;
    ll x;
    std::cin >> n;
    std::vector<ll> a;
    a.resize(n);
    for (auto &j : a)
        std::cin >> j;
    build(a, n);
    std::string command;
    while (std::cin >> command >> i >> j) {
        switch (command[1]) {
            case 'e':
                std::cin >> x;
                set(0, i - 1, j, x);
                break;
            case 'd':
                std::cin >> x;
                add(0, i - 1, j, x);
                break;
            case 'i':
                std::cout << min(0, i - 1, j) << std::endl;
                break;
        }
    }
    return 0;
}