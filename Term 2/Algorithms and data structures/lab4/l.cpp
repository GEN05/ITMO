#include <string>
#include <iostream>
#include <list>

class Set {
private:
    int MaxSize = 909526;
    std::list<int> set[909526];

    int hashCode(int n) const { // O(1)
        return abs(((n + INT32_MAX) * 123457) % 104473) % MaxSize;
    }

public:
    void write() {
        for (auto &i : set) {
            for (auto &j : i) {
                std::cout << j << ' ';
            }
            std::cout << '\n';
        }
    }

    void insert(int value) {
        if (!exist(value)) {
            set[hashCode(value)].push_back(value);
        }
    }

    void del(int value) {
        if (exist(value)) {
            for (auto &i : set[hashCode(value)]) {
                if (i == value) {
                    set[hashCode(value)].remove(value);
                    return;
                }
            }
        }
    }

    bool exist(int value) {     // O(n)
        for (auto &i : set[hashCode(value)]) {
            if (i == value)
                return true;
        }
        return false;
    }
};

int main() {
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string string;
    int value;
    Set set;
    while (std::cin >> string >> value) {
        switch (string[0]) {
            case 'i':
                set.insert(value);
                break;
            case 'e':
                std::cout << (set.exist(value) ? "true\n" : "false\n");
                break;
            case 'd':
                set.del(value);
                break;
            case 'w':
                set.write();
                break;
        }
    }
    return 0;
}