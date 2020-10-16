#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    n++;
    int m = (int) (log(n) / log(2)) + 1;
    std::vector<std::vector<int>> vector(n);
    vector[0].resize(m);
    for (int i = 1; i < n; i++) {
        vector[i].resize(m);
        std::cin >> vector[i][0];
    }
    for (int j = 1; j < m; j++)
        for (int i = 0; i < n; i++)
            vector[i][j] = vector[vector[i][j - 1]][j - 1];

    for (int i = 1; i < n; i++) {
        std::cout << i << ": ";
        for (int j : vector[i]) {
            if (j == 0)
                break;
            std::cout << j << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}