#include <iostream>

long long merge(int *c, int p, int q, int r) {
    int n = q - p + 1, i = 0, j = 0, m = r - q;
    long long cnt = 0;
    int *a = new int[n];
    int *b = new int[m];
    for (int k = 0; k < n; k++) {
        a[k] = c[p + k];
    }
    for (int k = 0; k < m; k++) {
        b[k] = c[q + 1 + k];
    }
    while (i + j < n + m) {
        if (j == m || (i < n && a[i] < b[j])) {
            c[p + i + j] = a[i];
            i++;
        } else {
            c[p + i + j] = b[j];
            j++;
            cnt += n - i;
        }
    }
    delete[]a;
    delete[]b;
    return cnt;
}

long long mergeSort(int *a, int l, int r) {
    long long cnt = 0;
    if (l >= r) {
        return 0;
    }
    int m = (l + r) / 2;
    cnt += mergeSort(a, l, m);
    cnt += mergeSort(a, m + 1, r);
    cnt += merge(a, l, m, r);
    return cnt;
}

int main() {
    int n;
    std::cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::cout << mergeSort(a, 0, n - 1);
    delete[]a;
    return 0;
}