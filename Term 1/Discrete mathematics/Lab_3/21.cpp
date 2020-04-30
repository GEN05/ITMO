#include <iostream>
#include <vector>

std::vector<std::vector<int>> dp;
std::vector<int> part;
int n, numOfPart = 0, last = 0, sum = 0;
std::string string;

int main() {
    std::cin >> string;
    for (int i = 0; i < string.length(); i+=2) part.push_back((int)string[i] - 48);
    for (int i : part) {
        n += i;
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    dp.resize(n);
    for (int i = 0; i < n; i++) {
        dp[i].resize(n);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dp[i][j] = 1;
            } else if (i < j) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i][j + 1] + dp[i - j][j];
            }
            std::cout << dp[i][j];
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < part.size(); i++) {
        for (int j = last; j < part[i]; j++) {
            numOfPart += dp[n - sum - j - 1][j];
        }
        sum += part[i];
        last = part[i];
    }
    std::cout << numOfPart;
    return 0;
}
