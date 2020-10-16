#include <iostream>
#include <vector>
#include <algorithm>

void writeAll(const std::vector<std::pair<int, int>>& all, const std::vector<int>& left, const std::vector<int>& right) {
    std::cout << "\nAll\n";
    for (auto &i : all)
        std::cout << i.first << '\t' << i.second << '\n';
    std::cout << "\nLeft\n";
    for (auto &i : left)
        std::cout << i << '\t';
    std::cout << "\nRight\n";
    for (auto &i : right)
        std::cout << i << '\t';
}

bool comparatorD(std::pair<int, int> a, std::pair<int, int> b) {
    return a.first > b.first;
}

int runD() {
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    int n, sum = 0, sumLeft = 0, sumRight = 0;
    std::cin >> n;
    std::vector<std::pair<int, int>> all(n); // key - index
    std::vector<int> left, right;
    for (int i = 0; i < n; i++) {
        std::cin >> all[i].first;
        all[i].second = i + 1;
        sum += all[i].first;
    }
    std::sort(all.begin(), all.end(), comparatorD);
    for (auto &i : all) {
        if (sumLeft < sumRight) {
            sumLeft += i.first;
            left.push_back(i.second);
        } else {
            sumRight += i.first;
            right.push_back(i.second);
        }
    }

    //std::cout << sum << '\t' << sumLeft << '\t' << sumRight;
    if (sumLeft == sumRight && sumRight == sum / 2) {
        std::cout << left.size() << '\n';
        for (auto &i : left)
            std::cout << i << ' ';
    } else
        std::cout << -1;

    //writeAll(all, left, right);

    return 0;
}
