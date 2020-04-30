#include <iostream>
#include <vector>

std::vector<std::vector<int>> dp;
std::vector<std::vector<int>> cost;
std::vector<char> ans;
int n, m, x, y;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::cin >> n >> m;
    x = n;
    y = m;
    dp.resize(n + 1);
    cost.resize(n + 1);
    dp[0].resize(m + 1);
    cost[0].resize(m + 1);
    for (int i = 1; i <= n; i++) {
        dp[i].resize(m + 1);
        cost[i].resize(m + 1);
        for (int j = 1; j <= m; j++) {
            std::cin >> cost[i][j];
        }
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = -10001;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = -10001;
    }
    dp[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]) + cost[i][j];
        }
    }
    while (x != 1 || y != 1) {
        if (dp[x - 1][y] > dp[x][y - 1]) {
            ans.push_back('D');
            x--;
        } else {
            ans.push_back('R');
            y--;
        }
    }
    std::cout << dp[n][m] << '\n';
    for (int i = ans.size() - 1; i >= 0; i--) {
        std::cout << ans[i];
    }
    return 0;
}
