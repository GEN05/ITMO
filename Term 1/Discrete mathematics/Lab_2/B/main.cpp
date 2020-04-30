#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> a;
std::string s, temp;
int len, k = 1;
char chtemp;

int main() {
    freopen("bwt.in", "r", stdin);
    freopen("bwt.out", "w", stdout);
    std::cin >> s;
    len = s.length();
    a.resize(len);
    a[0] = s;
    for (int i = 1; i < len; i++) {
        for (int j = 0; j < len - 1; j++) {
            temp += s[j + 1];
        }
        chtemp = s[0];
        temp += chtemp;
        a[k] = temp;
        s = temp;
        k++;
        temp = "";
    }
    std::sort(a.begin(), a.end());
    for (int i = 0; i < len; i++) {
        std::cout << a[i][len - 1];
    }
    return 0;
}