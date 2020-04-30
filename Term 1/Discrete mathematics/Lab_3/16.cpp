#include <iostream>
#include <vector>

std::vector<int> choose;
int n, k;
long long numOfChoose;

long long funcChoose(int up, int down) {
    long long sum = 1;
    for (int i = 1; i <= up - down; i++) {
        sum = sum * (down + i) / i;
    }
    return sum;
}

int main() {
    freopen("choose2num.in", "r", stdin);
    freopen("choose2num.out", "w", stdout);
    std::cin >> n >> k;
    choose.resize(k + 1);
    choose[0] = 0;
    for (int i = 1; i <= k; i++) {
        std::cin >> choose[i];
    }
    numOfChoose = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = choose[i - 1] + 1; j < choose[i]; j++) {
            numOfChoose += funcChoose(n - j, k - i);
        }
    }
    std::cout << numOfChoose;
    return 0;
}
