#include <iostream>

int main() {
    long long int n, w, h, counth = 1, countw = 0;
    std::cin >> w >> h >> n;
    if (w > h) {
        std::swap(h, w);
    }
    do {
        if (((counth + 1) * h) >= ((countw + 1) * w)) {
            n -= counth;
            countw++;
        } else {
            n -= countw;
            counth++;
        }
    } while (n > 0);
    std::cout << __max(counth * h, countw * w);
    return 0;
}