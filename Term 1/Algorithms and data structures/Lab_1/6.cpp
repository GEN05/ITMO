#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;
    int *a = new int[n];
    int *b = new int[k];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < k; i++) {
        std::cin >> b[i];
        int l = -1;
        int r = n;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (a[m] <= b[i]) {
                l = m;
            } else {
                r = m;
            }
        }
        if (l == -1) {
            std::cout << a[0] << std::endl;
        } else {
            if (l != n - 1) {
                if (b[i] - a[l] <= a[l + 1] - b[i]) {
                    std::cout << a[l] << std::endl;
                } else {
                    std::cout << a[l + 1] << std::endl;
                }
            } else {
                std::cout << a[l] << std::endl;
            }
        }
    }
    return 0;
}