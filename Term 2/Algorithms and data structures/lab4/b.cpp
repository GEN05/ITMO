#include <iostream>
#include <vector>
#include <algorithm>

bool compartorB(std::pair<int, int> &a, std::pair<int, int> &b) {
    return a.second < b.second;
}

int runB() {
    //freopen("request.in", "r", stdin);
    //freopen("request.out", "w", stdout);
    int n, counter = 0;
    std::cin >> n;
    std::vector<std::pair<int, int>> a(n);
    for (auto &i : a)
        std::cin >> i.first >> i.second;
    std::sort(a.begin(), a.end(), compartorB);
//    for (auto &i : a)
//        std::cout << i.first << " " << i.second << "\n";
    int now = 0;
    for (auto &i: a)
        if (now <= i.first) {
            counter++;
            now = i.second;
        }
    std::cout << counter;
    return 0;
}

/*
 * TEST
    7
    7 10
    4 5
    4 8
    1 3
    2 6
    12 13
    9 11
 */