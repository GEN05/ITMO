#include <iostream>

void merge(int *c, int p, int q, int r) {
    int n = q - p + 1, i = 0, j = 0, m = r - q;
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
        }
    }
    delete[]a;
    delete[]b;
}

void mergeSort(int *a, int l, int r) {
    if (l >= r) {
        return;
    }
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

int main() {
    int n, k, begin, end;
    std::cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    mergeSort(a, 0, n - 1);

    std::cin >> k;

    for (int i = 0; i < k; i++) {
        std::cin >> begin >> end;
        int l = -1, r = n;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (a[m] < begin) {
                l = m;
            } else {
                r = m;
            }
        }
        int res = r;
        l = -1, r = n;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (a[m] <= end) {
                l = m;
            } else {
                r = m;
            }
        }
        int res0 = l;
        std::cout << res0 - res + 1 << " ";
    }
    return 0;
}