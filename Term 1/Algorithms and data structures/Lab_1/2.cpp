#include <iostream>

void countsort(int *a, int *c, int n, int k) {
    for (int i = 0; i < k; i++) {
        c[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        c[a[i]] = c[a[i]] + 1;
    }
    int i = 0;
    for (int j = 0; j < k; j++) {
        while (c[j] != 0) {
            a[i] = j;
            c[j]--;
            i++;
        }
    }
}

int main() {
    int k = 101, i = 0, n = 200000, len = 0;
    int *a = new int[n];
    int *c = new int[k];
    while (std::cin >> a[i]) {
        i++;
        len++;
    }
    countsort(a, c, len, k);
    for (int j = 0; j < len; j++) {
        std::cout << a[j] << " ";
    }
    return 0;
}