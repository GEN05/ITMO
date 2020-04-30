#include <iostream>
#include <vector>

std::vector<long long> a, b;
int n;
long long ans = 0;

void func_200IQ() {
    a[0] = b[4] + b[6];
    a[1] = b[6] + b[8];
    a[2] = b[7] + b[9];
    a[3] = b[4] + b[8];
    a[4] = b[0] + b[3] + b[9];
    a[5] = 0;
    a[6] = b[0] + b[1] + b[7];
    a[7] = b[2] + b[6];
    a[8] = b[1] + b[3];
    a[9] = b[2] + b[4];
}

int main() {
    std::cin >> n;
    a.resize(10), b.resize(10);
    for (int i = 0; i < 10; i++) a[i] = 1;
    a[0] = 0, a[8] = 0;
    if (n == 1) ans = 8;
    else {
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 10; j++) b[j] = a[j] % 1000000000;
            func_200IQ();
        }
        for (int i = 0; i < 10; i++) ans += a[i] % 1000000000;
    }
    std::cout << ans % 1000000000;
}