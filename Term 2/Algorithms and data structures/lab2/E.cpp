#include <iostream>

typedef long long ll; // нужно ли? видимо нет: х < 1Е9

#define zero nullptr
#define yes true
#define no false

struct NODE {
    int value;
    int priority;
    int size;
    NODE *left{};
    NODE *right{};

    explicit NODE(int x) {
        value = x;
        priority = rand();
        size = 1;
    }
};

typedef NODE *nd;
typedef std::pair<nd, nd> pair;

int size(nd root) {
    return (root == zero) ? 0 : root->size;
}

void resize(nd root) {
    if (root != zero)
        root->size = size(root->left) + size(root->right) + 1;
}

pair split(nd root, int x) {
    pair p(zero, zero);
    if (root == zero)
        return p;
    if (root->value < x) {
        p = split(root->right, x);
        root->right = p.first;
        resize(root);
        return std::make_pair(root, p.second);
    } else {
        p = split(root->left, x);
        root->left = p.second;
        resize(root);
        return std::make_pair(p.first, root);
    }
}

nd merge(nd A, nd B) {
    if (A == zero) {
        resize(B);
        return B;
    }
    if (B == zero) {
        resize(A);
        return A;
    }
    if (A->priority > B->priority) {
        A->right = merge(A->right, B);
        resize(A);
        return A;
    } else {
        B->left = merge(A, B->left);
        resize(B);
        return B;
    }
}

nd insert(nd root, nd node) {
    if (root == zero) {
        resize(node);
        return node;
    }
    if (root->priority < node->priority) {
        pair p = split(root, node->value);
        node->left = p.first;
        node->right = p.second;
        resize(node);
        return node;
    } else {
        if (node->value < root->value)
            root->left = insert(root->left, node);
        else
            root->right = insert(root->right, node);
        resize(root);
        return root;
    }
}

nd remove(nd root, int x) {
    if (root->value > x)
        root->left = remove(root->left, x);
    else if (root->value < x)
        root->right = remove(root->right, x);
    else
        root = merge(root->left, root->right);
    resize(root);
    return root;
}

bool exists(nd root, int x) {
    if (root == zero)
        return no;
    if (root->value == x)
        return yes;
    if (x < root->value)
        return exists(root->left, x);
    else
        return exists(root->right, x);
}

nd next(nd root, int x) {
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

nd prev(nd root, int x) {
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

int kthMax(nd root, int k) {
    int left = size(root->left);
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
        std::cout << A->value << std::endl;
        write(A->left);
    }
}

int main() {
    int n, x;
    std::string operation;
    nd root = zero;
    nd node;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> operation >> x;
        switch (operation[0]) {
            case '1':
            case '+':
                node = new NODE(x);
                root = insert(root, node);
                break;
            case '0':
                std::cout << kthMax(root, size(root) - x + 1) << std::endl;
                break;
            case '-':
                root = remove(root, x);
                break;
            case 'w':
                write(root);
                break;
        }
    }
    return 0;
}