#include <iostream>
 
#define black true
#define white false
 
struct Node {
    int left = 0;
    int right = 0;
    int count = 0;
    int length = 0;
    bool isLeft{};
    bool isRight{};
    short color = 0;
};
 
void write(Node *tree) {
    std::cout << tree[0].count << " " << tree[0].length << std::endl;
}
 
int next_pow(int n) {
    int pow = 1;
    while (pow < n) {
        pow <<= 1;
    }
    return pow;
}
 
void make_good(int i, Node *tree) {
    switch (tree[i].color) {
        case white :
            tree[i] = {tree[i].left, tree[i].right, 0, 0, false, false, white};
            break;
        case black :
            tree[i] = {tree[i].left, tree[i].right, 1, tree[i].right - tree[i].left, true, true, black};
            break;
    }
}
 
void add(int i, Node *tree) {
    make_good(i, tree);
    if (tree[i].color < 2) {
        tree[2 * i + 1].color = tree[2 * i + 2].color = tree[i].color;
        make_good(2 * i + 1, tree);
        make_good(2 * i + 2, tree);
    }
}
 
void del(int i, Node *tree) {
    tree[i].count = tree[2 * i + 1].count + tree[2 * i + 2].count -
            (tree[2 * i + 1].isRight && tree[2 * i + 2].isLeft);
    tree[i].length = tree[2 * i + 1].length + tree[2 * i + 2].length;
    tree[i].isLeft = tree[2 * i + 1].isLeft;
    tree[i].isRight = tree[2 * i + 2].isRight;
    tree[i].color = (tree[2 * i + 1].color == tree[2 * i + 2].color ? tree[2 * i + 1].color : 96);
}
 
void update(int i, int l, int r, bool color, Node *tree) {
    if (l <= tree[i].left && tree[i].right <= r) {
        tree[i].count = tree[i].isLeft = tree[i].isRight = tree[i].color = color;
        tree[i].length = color * (tree[i].right - tree[i].left);
    } else {
        if (tree[i].right > l && r > tree[i].left) {
            add(i, tree);
            update(2 * i + 1, l, r, color, tree);
            update(2 * i + 2, l, r, color, tree);
            del(i, tree);
        } else {
            return;
        }
    }
}
 
void build(Node *tree, int size) {
    for (int i = 0; i < size; i++)
        tree[size - 1 + i] = {i, i + 1, 0, 0, white};
    for (int i = size - 2; i >= 0; i--)
        tree[i] = {tree[2 * i + 1].left, tree[2 * i + 2].right, 0, 0, white};
}
 
int main() {
    char ch;
    bool color;
    int n, x, l;
    std::cin >> n;
    int k = 1000000;
    int size = next_pow(k);
    Node *tree = new Node[size * 2 - 1];
    build(tree, size);
    for (int i = 0; i < n; i++) {
        std::cin >> ch >> x >> l;
        x += 500000;
        switch (ch) {
            case 'W':
                color = white;
                break;
            case 'B':
                color = black;
                break;
            default:
                throw std::exception();
        }
        update(0, x, x + l, color, tree);
        make_good(0, tree);
        write(tree);
    }
    return 0;
}