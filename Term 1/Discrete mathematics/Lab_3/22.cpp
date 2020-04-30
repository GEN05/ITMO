#include <iostream>
#include <vector>

std::vector<int> part;
std::vector<std::vector<int>> d;
int numOfPart = 0, last = 0, sum = 0, n = 0, temp, o;
char c;

int calculate(int l, int r) {
    if (l == r) return 1;
    if (l < r) return 0;
    if (l > r) return calculate(l, r + 1) + calculate(l - r, r);
}

int main() {
//    freopen("part2num.in", "r", stdin);
//    freopen("part2num.out", "w", stdout);
//    std::cin >> temp;
//    part.push_back(temp);
//    n = temp;
//    while (std::cin >> c) {
//        std::cin >> temp;
//        part.push_back(temp);
//        n += temp;
//    }
//    for (int i : part) {
//        std::cout << i << " ";
//    }
    std::cin >> o;
    std::cout << calculate(o, 0);
    part.resize(o + 1);
    part[0] = 0;
    for (int i = 1; i <= o; i++) {
        std::cin >> part[i];
        n += part[i];
    }
    for (int i = 1; i <= part.size(); i++) {
        for (int j = last; j < part[i]; j++) {
            numOfPart += calculate(n - sum - j, j);
        }
        sum += part[i];
        last = part[i];
    }
    std::cout << numOfPart;
    return 0;
}
