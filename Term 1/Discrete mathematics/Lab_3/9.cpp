#include <iostream>

int n;

void generate(int open, int close, std::string ans) {
    if (open + close == 2 * n) {
        std::cout << ans << '\n';
        return;
    }
    if (open < n) {
        generate(open + 1, close, ans + '(');
    }
    if (open > close) {
        generate(open, close + 1, ans + ')');
    }
}

int main() {
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    std::cin >> n;
    generate(0, 0, "");
    return 0;
}
