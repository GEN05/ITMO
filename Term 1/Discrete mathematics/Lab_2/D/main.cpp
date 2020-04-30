#include <iostream>
#include <vector>

int ascii = 97, kol = 26;
bool yes;
std::vector<std::string> a;
std::string s, temp, temp0;

int main() {
    freopen("lzw.in", "r", stdin);
    freopen("lzw.out", "w", stdout);
    a.resize(100000);
    for (int i = 0; i < kol; i++) {
        a[i] = char(ascii);
        ascii++;
    }
    std::cin >> s;
    if (s.length() != 0) {
        yes = true;
        temp = s[0];
        for (int i = 1; i < s.length(); i++) {
            yes = true;
            temp0 = s[i];
            for (int j = 0; j < a.size(); j++) {
                if (temp + temp0 == a[j]) {
                    yes = false;
                    temp += temp0;
                    break;
                }
            }
            if (yes) {
                for (int j = 0; j < a.size(); j++) {
                    if (temp == a[j]) {
                        a[kol] = temp + temp0;
                        temp = temp0;
                        kol++;
                        std::cout << j << " ";
                        break;
                    }
                }
            }
            if (i == s.length() - 1) {
                for (int j = 0; j < a.size(); j++) {
                    if (temp == a[j]) {
                        std::cout << j << " ";
                    }
                }
            }
        }
    }
    if (s.length() == 1) {
        for (int i = 0; i < a.size(); i++) {
            if (temp == a[i]) {
                std::cout << i << " ";
            }
        }
    }
    return 0;
}