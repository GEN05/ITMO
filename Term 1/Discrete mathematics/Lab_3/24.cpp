#include <iostream>
#include <vector>

std::vector<int> permutation;
int n, min, max;
bool flag = false;

std::vector<int> reverse(std::vector<int> c, int front, int back) {
    while ((front != back) && (front != --back)) std::swap(c[front++], c[back]);
    return c;
}

void nextPermutation(std::vector<int> next) {
    flag = false;
    for (int i = n - 2; i >= 0; i--) {
        if (next[i] < next[i + 1]) {
            flag = true;
            min = i + 1;
            for (int j = i + 1; j < n; j++) {
                if (next[j] < next[min] && next[j] > next[i]) min = j;
            }
            std::swap(next[i], next[min]);
            next = reverse(next, i + 1, n);
            break;
        }
    }
    if (!flag) for (int i = 0; i < n; i++) next[i] = 0;
    for (int i : next) {
        std::cout << i << " ";
    }
}

void previousPermutation(std::vector<int> prev) {
    flag = false;
    for (int i = n - 2; i >= 0; i--) {
        if (prev[i] > prev[i + 1]) {
            flag = true;
            max = i + 1;
            for (int j = i + 1; j < n; j++) {
                if (prev[j] > prev[max] && prev[j] < prev[i]) max = j;
            }
            std::swap(prev[i], prev[max]);
            prev = reverse(prev, i + 1, n);
            break;
        }
    }
    if (!flag) for (int i = 0; i < n; i++) prev[i] = 0;
    for (int i : prev) {
        std::cout << i << " ";
    }
}

int main() {
    freopen("nextperm.in", "r", stdin);
    freopen("nextperm.out", "w", stdout);
    std::cin >> n;
    permutation.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> permutation[i];
    }
    previousPermutation(permutation);
    std::cout << std::endl;
    nextPermutation(permutation);
    return 0;
}
