#include <iostream>
#include <vector>

std::vector<int> dp;
std::vector<int> cost;
std::vector<int> ans;
std::vector<int> ans1;
int n, k, jump = 0, max, t;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::cin >> n >> k;
    dp.resize(n), cost.resize(n);
    ans.push_back(1);
    dp[0] = 0;
    for (int i = 1; i < n - 1; i++) {
        std::cin >> cost[i];
    }
    for (int i = 1; i < n; i++) {
        max = -10001;
        jump = 0;
        for (int j = i - k; j < i; j++) {
            if (j >= 0 && dp[j] > max) {
                max = dp[j];
                jump = j + 1;
            }
        }
        dp[i] = cost[i] + max;
        ans.push_back(jump);
    }
    ans.push_back(n);
    t = (int) ans.size() - 1;
    while (ans[t] != 1) {
        ans1.push_back(ans[t]);
        t = ans[t] - 1;
    }
    ans1.push_back(1);
    std::cout << "\n" << dp[n - 1] << "\n" << ans1.size() - 1 << "\n";
    for (int i = ans1.size() - 1; i >= 0; i--) {
        std::cout << ans1[i] << " ";
    }
    return 0;
}
