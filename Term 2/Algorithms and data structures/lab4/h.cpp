#include <iostream>
#include <vector>

void gen(std::vector<std::vector<int>> &AllVector, std::vector<int> vector, int n, int cur, int countOfOne) {
    if (cur != n) {
        vector.push_back(0);
        gen(AllVector, vector, n, cur + 1, 0);
        vector.pop_back();
        if (countOfOne != 1 || cur == 0) {
            vector.push_back(1);
            gen(AllVector, vector, n, cur + 1, countOfOne + 1);
            vector.pop_back();
        }
    } else {
        AllVector.resize(AllVector.size() + 1);
        for (int &i : vector)
            AllVector[AllVector.size() - 1].push_back(i);
    }
}

int runH() {
    freopen("vectors2.in", "r", stdin);
    freopen("vectors2.out", "w", stdout);
    int n;
    std::cin >> n;
    std::vector<int> garbage;
    std::vector<std::vector<int>> Allvector;
    gen(Allvector, garbage, n, 0, 0);
    std::cout << Allvector.size() << '\n';
    for (auto &i : Allvector) {
        for (auto &j : i)
            std::cout << j;
        std::cout << '\n';
    }
    return (0 + 0) * (0 - 0);
}