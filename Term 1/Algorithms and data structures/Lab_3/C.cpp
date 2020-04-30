#include <iostream>
#include <vector>

int n, pos, length;
std::vector<int> a;
std::vector<int> ans;

std::vector<int> findLIS() {
    std::vector<int> prev, d, answer;
    prev.resize(n), d.resize(n);
    for (int i = 0; i < n; i++) {
        d[i] = 1;
        prev[i] = -1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && d[j] + 1 > d[i]) {
                d[i] = d[j] + 1;
                prev[i] = j;
            }
        }
    }
    pos = 0;
    length = d[0];
    for (int i = 0; i < n; i++) {
        if (d[i] > length) {
            pos = i;
            length = d[i];
        }
    }
    while (pos != -1) {
        answer.push_back(a[pos]);
        pos = prev[pos];
    }
    return answer;
}

int main() {
    std::cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    ans = findLIS();
    std::cout << ans.size() << '\n';
    for (int i = ans.size() - 1; i >= 0; i--) {
        std::cout << ans[i] << " ";
    }
    return 0;
}