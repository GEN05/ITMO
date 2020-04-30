#include <iostream>
#include <algorithm>
#include <vector>

const int N = 1e6 + 100;

#define x first
#define  y second

int v[N], w[N];
int n, k;
double q[N];
std::vector<std::pair<double, int>> ans;

bool check(double x) {
    for (int i = 0; i < n; i++) {
        q[i] = v[i] - x * w[i];
    }

    std::sort(q, q + n);

    double sum = 0;
    for (int i = n - k; i < n; i++) {
        sum += q[i];
    }

    return (sum >= 0);
}

int main() {

    std::cin >> n >> k;

    for (int i = 0; i < n; i++) {
        std::cin >> v[i] >> w[i];
    }

    double left = 0, right = 1e18 + 100;

    for (int i = 0; i < 100; i++) {
        double mid = (left + right) / 2;
        if (check(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    ans.resize(n);
    for (int i = 0; i < n; i++) {
        ans[i] = {v[i] - left * w[i], i};
    }

    sort(ans.begin(), ans.end());

    std::vector<int> ans2;

    for (int i = n - k; i < n; i++) {
        ans2.push_back(ans[i].y + 1);
    }

    sort(ans2.begin(), ans2.end());

    for (int i : ans2) {
        std::cout << i << std::endl;
    }

    return 0;
}