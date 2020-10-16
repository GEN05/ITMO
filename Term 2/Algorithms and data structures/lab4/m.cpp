#include <string>
#include <iostream>
#include <list>
#include <cmath>

class Map {
private:
    int MaxSize = 909526;
    std::list<std::pair<std::string, std::string>> map[909526];

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
        if (!exist(key))
            map[hashCode(key)].emplace_back(key, value);
        else
            for (auto &i : map[hashCode(key)])
                if (i.first == key)
                    i.second = value;
    }

    void del(const std::string &key) {
        std::string value = get(key);
        if (!value.empty()) {
            for (auto &i : map[hashCode(key)]) {
                if (i.first == key) {
                    map[hashCode(key)].remove(std::make_pair(key, value));
                    return;
                }
            }
        }
    }

    std::string get(const std::string &key) {
        for (auto &i : map[hashCode(key)])
            if (i.first == key)
                return i.second;
        return "";
    }

    bool exist(const std::string &key) {     // O(n)
        return !get(key).empty();
    }
};

int main() {
    freopen("map.in", "r", stdin);
    freopen("map.out", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string operation, key, value;
    Map map;
    while (std::cin >> operation >> key) {
        switch (operation[0]) {
            case 'p':
                std::cin >> value;
                map.insert(key, value);
                break;
            case 'g':
                value = map.get(key);
                value.empty() ? std::cout << "none\n" : std::cout << value << '\n';
                break;
            case 'd':
                map.del(key);
                break;
            case 'w':
                map.write();
                break;
            case 'e':
                map.exist(key);
                break;
        }
    }
    return 0;
}