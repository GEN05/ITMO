#include <iostream>
#include <vector>
#include <algorithm>

int runA() {
    freopen("cobbler.in", "r", stdin);
    freopen("cobbler.out", "w", stdout);
    int k, n, counter = 0;
    std::cin >> k >> n;
    std::vector<int> a(n);
    for (auto &i : a)
        std::cin >> i;
    std::sort(a.begin(), a.end());
    for (auto &i : a)
        if (k - i >= 0) {
            counter++;
            k -= i;
        }
    std::cout << counter;
    return 0;
}