#include <iostream>
#include <vector>

std::vector<int> a;
std::vector<int> size;
int n, p, last = -1, kol = 0, ans = 0;

int main() {
    std::cin >> n;
    a.resize(n);
    size.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p;
        if (p == last) {
            ans++;
            continue;
        }
        if (kol && a[kol - 1] == p) {
            if (size[kol - 1] == 2) {
                kol--;
                last = p;
                ans += 3;
            } else {
                last = -1;
                size[kol - 1]++;
            }
            continue;
        }
        last = -1;
        a[kol] = p;
        size[kol++] = 1;
    }
    std::cout << ans;
    return 0;
}