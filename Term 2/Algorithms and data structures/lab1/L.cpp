#include <iostream>
#include <vector>

typedef long long lol;

std::vector<std::vector<std::vector<lol>>> $za75;
// дорога в ад программиста усеяна глобальными переменными
// не бейте, я просто не смог сделать нормальные указатели \_(ツ)_/¯

int IQ200Function(int i) {
    return (i & (i + 1)) - 1;
}

int Function200IQ(int i) {
    return i | (i + 1);
}

lol sum(int a, int b, int c) {
    lol answer = 0;
    for (int i = a; i >= 0; i = IQ200Function(i))
        for (int j = b; j >= 0; j = IQ200Function(j))
            for (int k = c; k >= 0; k = IQ200Function(k))
                answer += $za75[i][j][k];
    return answer;
}

void inclusion_exception(int x1, int y1, int z1, int x2, int y2, int z2) {
    x1--;
    y1--;
    z1--;
    std::cout << sum(x2, y2, z2) + sum(x2, y1, z1) +
                 sum(x1, y2, z1) + sum(x1, y1, z2) - (
                         sum(x1, y1, z1) + sum(x1, y2, z2) +
                         sum(x2, y1, z2) + sum(x2, y2, z1)
                 ) << std::endl;
}

void inc(int a, int b, int c, int delta, int n) {
    for (int i = a; i < n; i = Function200IQ(i))
        for (int j = b; j < n; j = Function200IQ(j))
            for (int k = c; k < n; k = Function200IQ(k))
                $za75[i][j][k] += delta;
}

int main() {
    int n, choose, x, y, z, k, x1, y1, z1, x2, y2, z2;
    std::cin >> n;
    $za75.resize(n);
    for (auto &i : $za75) {
        i.resize(n);
        for (auto &j : i)
            j.resize(n);
    }
    while (std::cin >> choose) {
        switch (choose) {
            case 1:
                std::cin >> x >> y >> z >> k;
                inc(x, y, z, k, n);
                break;
            case 2:
                std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
                inclusion_exception(x1, y1, z1, x2, y2, z2);
                break;
            case 3:
                return 0;
            default:
                throw std::exception();
        }
    }
    return 0;
}