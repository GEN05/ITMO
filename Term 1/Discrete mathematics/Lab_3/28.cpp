#include <iostream>
#include <vector>

int n;
std::vector<int> multiperm;

std::vector<int> reverse(std::vector<int> c, int front, int back) {
    while ((front != back) && (front != --back)) std::swap(c[front++], c[back]);
    return c;
}

bool nextMultiPerm() {
    int i = n - 2;
    while (i >= 0 && multiperm[i] >= multiperm[i + 1]) i--;
    if (i < 0) {
        return false;
    } else {
        int j = i + 1;
        while (j < n - 1 && multiperm[j + 1] > multiperm[i]) j++;
        std::swap(multiperm[i], multiperm[j]);
        multiperm = reverse(multiperm, i + 1, n);
        return true;
    }
}

int main() {
    freopen("nextmultiperm.in","r",stdin);
    freopen("nextmultiperm.out","w",stdout);
    std::cin >> n;
    multiperm.resize(n);
    for (int i = 0; i < n; i++) std::cin >> multiperm[i];
    if (!nextMultiPerm()) {
        for (int i : multiperm){
            std::cout << 0 << " ";
        }
    } else {
        for (int k : multiperm) {
            std::cout << k << " ";
        }
    }
    return 0;
}
