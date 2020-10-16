#include <string>
#include <iostream>
#include <list>
#include <cmath>

class LinkedMap {
private:
    int MaxSize = 909526;
    int Size = 0;
    std::list<std::pair<std::string, std::string>> linkedmap[909526];

    int hashCode(std::string string) const {
        int res = 0;
        int n = string.length();
        for (int i = 0; i < n; i++)
            res += string[i] * (std::pow(31, n - i));
        return abs(res) % MaxSize;
    }
public:

    void write() {
    }

    void insert(const std::string &key, const std::string &value) {
        if (!exist(key)) {
            linkedmap[hashCode(key)].emplace_back(key, value);
            Size++;
        } else
            for (auto &i : linkedmap[hashCode(key)])
                if (i.first == key)
                    i.second = value;
    }

    void del(const std::string &key) {
        std::string value = get(key);
        if (!value.empty()) {
            for (auto &i : linkedmap[hashCode(key)]) {
                if (i.first == key) {
                    linkedmap[hashCode(key)].remove(std::make_pair(key, value));
                    Size--;
                    return;
                }
            }
        }
    }

    std::string get(const std::string &key) {
        for (auto &i : linkedmap[hashCode(key)])
            if (i.first == key)
                return i.second;
        return "";
    }

    bool exist(const std::string &key) {     // O(n)
        return !get(key).empty();
    }

    std::string prev(std::string key) {

    }

    std::string next(std::string key) {

    }
};

int runN() {
//    freopen("linkedmap.in", "r", stdin);
//    freopen("linkedmap.out", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    std::cin.tie(nullptr);
    std::string operation, key, value;
    LinkedMap linkedmap;
    while (std::cin >> operation >> key) {
        switch (operation[0]) {
            case 'p':
                std::cin >> value;
                linkedmap.insert(key, value);
                break;
            case 'g':
                value = linkedmap.get(key);
                value.empty() ? std::cout << "none\n" : std::cout << value << '\n';
                break;
            case 'd':
                linkedmap.del(key);
                break;
            case 'w':
                linkedmap.write();
                break;
            case 'e':
                linkedmap.exist(key);
                break;
        }
    }
    return 0;
}