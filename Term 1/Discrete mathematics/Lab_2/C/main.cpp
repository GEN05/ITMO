#include <iostream>
#include <vector>

int ascii = 97, temp;
std::vector <char> a;
std::string s;

int main() {
    freopen("mtf.in","r",stdin);
    freopen("mtf.out","w",stdout);
    a.resize(26);
    for (int i = 0; i < 26; i++) {
        a[i] = char(ascii);
        ascii++;
    }
    std::cin >> s;
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < 26; j++) {
            if (a[j] == s[i]) {
                temp = j;
                std::cout << j + 1 << " ";
                break;
            }
        }
        for (int j = temp; j > 0; j--) {
            a[j] = a[j - 1];
        }
        a[0] = s[i];
    }
    return 0;
}