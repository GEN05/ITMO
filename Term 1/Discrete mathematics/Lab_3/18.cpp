#include <iostream>
#include <vector>

std::vector<std::vector<long long>> dp;
long long n, number = 0, depth = 0;
std::string string;

int main() {
    freopen("brackets2num.in", "r", stdin);
    freopen("brackets2num.out", "w", stdout);
    std::cin >> string;
    n = string.length() / 2;
    dp.resize(2 * n + 1);
    for (int i = 0; i <= 2 * n; i++) {
        dp[i].resize(2 * n + 1);
        dp[0][i] = 0;
    }
    dp[0][0] = 1;
    for (int i = 1; i < 2 * n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            dp[i][j] = j == 0 ? dp[i - 1][j + 1] : dp[i - 1][j - 1] + dp[i - 1][j + 1];
        }
    }
    for (int i = 0; i < 2 * n; i++) {
        if (string[i] == '(') {
            depth++;
        } else {
            number += dp[2 * n - i - 1][depth + 1];
            depth--;
        }
    }
    std::cout << number;
    return 0;
}
