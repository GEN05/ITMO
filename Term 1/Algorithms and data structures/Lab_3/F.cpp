#include <iostream>
#include <vector>
#include <algorithm>

const int inf = 30000000;
std::vector<std::vector<int>> dp;
std::vector<int> a;
int n, answer, index, indexTemp;
std::vector<int> cost;

int main() {
    std::cin >> n;
    cost.resize(n);
    dp.resize(n + 1);
    for (int i = 0; i < n; i++) {
        dp[i].resize(n + 1);
        std::cin >> cost[i];
        dp[0][i] = inf;
        dp[i][0] = 0;
    }
    dp[n].resize(n + 1);
    dp[0][n] = inf;
    dp[n][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j > i) dp[i][j] = inf;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (cost[i - 1] > 100) {
                if (j == 0) {
                    dp[i][j] = std::min(inf + cost[i - 1], dp[i - 1][j + 1]);
                } else {
                    dp[i][j] = std::min(dp[i - 1][j - 1] + cost[i - 1], dp[i - 1][j + 1]);
                }
            } else {
                dp[i][j] = std::min(dp[i - 1][j] + cost[i - 1], dp[i - 1][j + 1]);
            }
        }
    }
    answer = dp[n][0];
    index = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[n][i] > 0 && dp[n][i] <= answer) {
            answer = dp[n][i];
            index = i;
        }
    }
    indexTemp = index;
    if (answer != 0)
        while (n > 0) {
            if (cost[n - 1] > 100) {
                if (dp[n][indexTemp] == dp[n - 1][indexTemp + 1]) {
                    a.push_back(n);
                    n--;
                    indexTemp++;
                } else {
                    n--;
                    indexTemp--;
                }
            } else {
                if (dp[n][indexTemp] == dp[n - 1][indexTemp + 1]) {
                    a.push_back(n);
                    n--;
                    indexTemp++;
                } else
                    n--;
            }
        }
    std::sort(a.begin(), a.end());
    std::cout << answer << std::endl << index << " " << a.size() << std::endl;
    for (int i : a) std::cout << i << std::endl;
    return 0;
}