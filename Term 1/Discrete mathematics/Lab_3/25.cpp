#include <iostream>
#include <vector>

std::vector<int> choose;
int n, k;

bool nextChoose() {
    int i = k - 1;
    while (i >= 0 && choose[i + 1] - choose[i] < 2) i--;
    if (i >= 0) {
        choose[i]++;
        for (int j = i + 1; j < k; j++) choose[j] = choose[j - 1] + 1;
        for (int j = 0; j < k; j++) {
            std::cout << choose[j] << " ";
        }
        return true;
    } else {
        return false;
    }
}

int main() {
    freopen("nextChoose.in", "r", stdin);
    freopen("nextChoose.out", "w", stdout);
    std::cin >> n >> k;
    choose.resize(k + 1);
    for (int i = 0; i < k; i++) std::cin >> choose[i];
    choose[k] = n + 1;
    if (!nextChoose()) std::cout << "-1";
    return 0;
}
