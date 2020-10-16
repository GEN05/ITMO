#include <iostream>

typedef long long ll; // нужно ли? видимо нет: х < 1Е9

#define zero nullptr
#define yes true
#define no false
#define INF 1000000000

struct NODE {
    ll value;
    ll priority;
    ll sum;
    NODE *left{};
    NODE *right{};

    explicit NODE(ll x) {
        sum = value = x;
        priority = rand() * rand();
    }
};

typedef NODE *nd;
typedef std::pair<nd, nd> pair;

ll sum(nd root) {
    return (root == zero) ? 0 : root->sum;
}

void recalc(nd root) {
    if (root != zero)
        root->sum = sum(root->left) + sum(root->right) + root->value;
}

pair split(nd root, ll x) {
    pair p(zero, zero);
    if (root == zero) {
        recalc(root);
        return p;
    }
    if (root->value < x) {
        p = split(root->right, x);
        root->right = p.first;
        recalc(root);
        return std::make_pair(root, p.second);
    } else {
        p = split(root->left, x);
        root->left = p.second;
        recalc(root);
        return std::make_pair(p.first, root);
    }
}

nd merge(nd A, nd B) {
    if (A == zero) {
        return B;
    }
    if (B == zero) {
        return A;
    }
    if (A->priority > B->priority) {
        A->right = merge(A->right, B);
        recalc(A);
        return A;
    } else {
        B->left = merge(A, B->left);
        recalc(B);
        return B;
    }
}

nd insert(nd root, nd node) {
    if (root == zero) {
        recalc(node);
        return node;
    }
    if (root->priority < node->priority) {
        pair p = split(root, node->value);
        node->left = p.first;
        node->right = p.second;
        recalc(node);
        return node;
    } else {
        if (node->value < root->value)
            root->left = insert(root->left, node);
        else
            root->right = insert(root->right, node);
        recalc(root);
        return root;
    }
}

nd remove(nd root, ll x) {
    if (root->value > x)
        root->left = remove(root->left, x);
    else if (root->value < x)
        root->right = remove(root->right, x);
    else
        root = merge(root->left, root->right);
    recalc(root);
    return root;
}

bool exists(nd root, ll x) {
    if (root == zero)
        return no;
    if (root->value == x)
        return yes;
    if (x < root->value)
        return exists(root->left, x);
    else
        return exists(root->right, x);
}

nd next(nd root, ll x) {
    nd cur = root;
    nd answer = zero;
    while (cur != zero) {
        if (cur->value > x) {
            answer = cur;
            cur = cur->left;
        } else
            cur = cur->right;
    }
    return answer;
}

nd prev(nd root, ll x) {
    nd cur = root;
    nd answer = zero;
    while (cur != zero) {
        if (cur->value < x) {
            answer = cur;
            cur = cur->right;
        } else
            cur = cur->left;
    }
    return answer;
}

ll kthMax(nd root, ll k) {
    ll left = sum(root->left);
    if (left + 1 == k)
        return root->value;
    if (k <= left) {
        return kthMax(root->left, k);
    } else
        return kthMax(root->right, k - left - 1);
}

void write(nd A) {
    if (A != zero) {
        write(A->left);
        std::cout << A->value << "___";
        write(A->right);
    }
}

ll findSUM(nd root, ll left, ll right) {
    pair pair1 = split(root, right);
    pair pair2 = split(pair1.first, left);
    ll res = sum(pair2.second);
    root = merge(pair2.first, merge(pair2.second, pair1.second));
    return res;
}

int main() {
    ll n, x, y, res;
    std::string operation;
    bool module = no;
    nd root = zero;
    nd node;
    std::cin >> n;
    for (ll i = 0; i < n; i++) {
        std::cin >> operation >> x;
        switch (operation[0]) {
            case '+':
                if (module) {
                    x += res;
                    x %= INF;
                }
                if (!exists(root, x)) {
                    node = new NODE(x);
                    root = insert(root, node);
                }
                module = no;
                break;
            case '?':
                std::cin >> y;
                res = findSUM(root, x, y + 1);
                std::cout << res << std::endl;
                module = yes;
                break;
            case 'w':
                write(root);
                break;
            case 'c':
                return 0;
        }
    }
    return 0;
}