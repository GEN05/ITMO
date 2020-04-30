#include <iostream>
#include <vector>

std::vector<std::vector<long long>> dp;
long long n, k, depth = 0;
std::string string;

int main() {
    freopen("num2brackets.in", "r", stdin);
    freopen("num2brackets.out", "w", stdout);
    std::cin >> n >> k;
    k++;
    string = "";
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
        if (dp[2 * n - i - 1][depth + 1] < k || n - 1 < depth) {
            if (depth + 1 <= n) k -= dp[2 * n - i - 1][depth + 1];
            string += ')';
            depth--;
        } else {
            string += '(';
            depth++;
        }
    }
    std::cout << string;
    return 0;
}
