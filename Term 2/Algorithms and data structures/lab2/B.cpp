#include <iostream>

typedef long long ll; // нужно ли? видимо нет: х < 1Е9

#define zero nullptr
#define yes true
#define no false

struct NODE {
    int value;
    int priority;
    NODE *left{};
    NODE *right{};

    explicit NODE(int x) {
        value = x;
        priority = rand();
    }
};

typedef NODE *nd;
typedef std::pair<nd, nd> pair;

pair split(nd root, int x) {
    pair p(zero, zero);
    if (root == zero)
        return p;
    if (root->value < x) {
        p = split(root->right, x);
        root->right = p.first;
        return std::make_pair(root, p.second);
    } else {
        p = split(root->left, x);
        root->left = p.second;
        return std::make_pair(p.first, root);
    }
}

nd merge(nd A, nd B) {
    if (A == zero)
        return B;
    if (B == zero)
        return A;
    if (A->priority > B->priority) {
        A->right = merge(A->right, B);
        return A;
    } else {
        B->left = merge(A, B->left);
        return B;
    }
}

nd insert(nd root, nd node) {
    if (root == zero)
        return node;
    if (root->priority < node->priority) {
        pair p = split(root, node->value);
        node->left = p.first;
        node->right = p.second;
        return node;
    } else {
        if (node->value < root->value)
            root->left = insert(root->left, node);
        else
            root->right = insert(root->right, node);
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

int main() {
    int x;
    std::string operation;
    nd root = zero;
    nd node;
    while (std::cin >> operation >> x) {
        switch (operation[0]) {
            case 'i': // insert
                if (!exists(root, x)) {
                    node = new NODE(x);
                    root = insert(root, node);
                }
                break;
            case 'd': // delete
                if (exists(root, x))
                    root = remove(root, x);
                break;
            case 'e': //exists
                if (exists(root, x))
                    std::cout << "true\n";
                else
                    std::cout << "false\n";
                break;
            case 'n': // next
                (next(root, x) != zero) ? std::cout << next(root, x)->value << std::endl : std::cout << "none" << std::endl;
                break;
            case 'p': // prev
                (prev(root, x) != zero) ? std::cout << prev(root, x)->value << std::endl : std::cout << "none" << std::endl;
                break;
            case 'c': // close
                return 0;

        }
    }
    return 0;
}