#include <iostream>
void merge(int* c, int p, int q, int r) {
    int n = q - p + 1, i = 0, j = 0, m = r - q;
    int* a = new int[n];
    int* b = new int[m];
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
    delete []a;
    delete []b;
}
void mergeSort(int* a, int l, int r) {
    if (l >= r)
    {
        return;
    }
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}
int main() {
    int n;
    std::cin >> n;
    int * a = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    mergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    delete []a;
    return 0;
}