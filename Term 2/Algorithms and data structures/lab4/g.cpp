#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int runG() {
    freopen("beautiful.in", "r", stdin);
    freopen("beautiful.out", "w", stdout);
    int n, r, ans = 0, counter = 0;
    std::cin >> n >> r;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    do {
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
            sum += a[i] * a[i + 1];
        sum %= r;
        int t = (int) sqrt(sum);
        counter = 0;
        for (int i = 1; i <= t; i++)
            if (!(sum % i)) {
                counter++;
                if (i != sum / i)
                    counter++;
            }
        if (counter % 3 == 0)
            ans++;
    } while (std::next_permutation(a.begin(), a.end()));
    std::cout << ans;
    return 0;
}
