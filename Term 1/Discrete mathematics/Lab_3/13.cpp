#include <iostream>
#include <vector>

std::vector<int> premutation;
std::vector<bool> was;
int n, curFree;
long long k, alreadyWas;

long long factorial(int p) {
    long long sum = 1;
    for (int i = 1; i <= p; i++) sum *= i;
    return sum;
}

int main() {
    freopen("num2perm.in", "r", stdin);
    freopen("num2perm.out", "w", stdout);
    std::cin >> n >> k;
    premutation.resize(n + 1), was.resize(n + 1);
    for (int i = 1; i < n + 1; i++) {
        alreadyWas = k / factorial(n - i);
        k %= factorial(n - i);
        curFree = 0;
        for (int j = 1; j < n + 1; j++) {
            if (was[j] == false) {
                curFree++;
                if (curFree == alreadyWas + 1) {
                    premutation[i] = j;
                    was[j] = true;
                }
            }
        }
    }
    for (int i = 1; i < n + 1; i++) {
        std::cout << premutation[i] << " ";
    }
    return 0;
}
