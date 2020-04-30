#include <iostream>
#include <vector>
#include <stack>

std::stack<int> a;
std::vector<std::string> ans;
std::vector<int> check;
int n, p, cur = 1;

int main() {
    std::cin >> n;
    check.resize(n + 1);
    for (int & i : check) {
        i = 0;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> p;
        a.push(p);
        check[p] = 1;
        ans.emplace_back("push");
        if (!a.empty() && a.top() == cur) {
            while (!a.empty() && a.top() == cur) {
                a.pop();
                ans.emplace_back("pop");
                cur++;
            }
            if (check[cur] == 1) {
                std::cout << "impossible";
                return 0;
            }
        }
    }
    for (const auto & an : ans) {
        std::cout << an << std::endl;
    }
    return 0;
}