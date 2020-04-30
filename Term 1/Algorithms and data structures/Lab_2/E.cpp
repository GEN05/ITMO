#include <iostream>
#include <vector>

std::vector<int> a;
char s;

int main() {
    while (std::cin >> s) {
        if (s == '+') {
            a[a.size() - 2] = a[a.size() - 2] + a[a.size() - 1];
            a.pop_back();
        } else if (s == '-') {
            a[a.size() - 2] = a[a.size() - 2] - a[a.size() - 1];
            a.pop_back();
        } else if (s == '*') {
            a[a.size() - 2] = a[a.size() - 2] * a[a.size() - 1];
            a.pop_back();
        } else {
            a.push_back((int) s - 48);
        }
    }
    std::cout << a.front();
    return 0;
}