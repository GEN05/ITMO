#include <iostream>
#include <vector>

std::vector<std::vector<int>> set;
int n, k;

void generateSet(const std::vector<std::vector<int>> &setTemp, int a, int b) {
    if (a != n + 1) {
        std::vector<int> temp;
        temp.push_back(a);
        for (int i = 0; i < setTemp.size(); i++) {
            auto setTemp2 = setTemp;
            setTemp2[i].push_back(a);
            generateSet(setTemp2, a + 1, b);
        }
        auto setTemp2 = setTemp;
        setTemp2.push_back(temp);
        generateSet(setTemp2, a + 1, b + 1);
    } else {
        if (b != k) return;
        for (const auto &hop: setTemp) {
            for (auto hey : hop) {
                std::cout << hey << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

int main() {
    freopen("part2sets.in", "r", stdin);
    freopen("part2sets.out", "w", stdout);
    std::cin >> n >> k;
    generateSet(set, 1, 0);
    return 0;
}