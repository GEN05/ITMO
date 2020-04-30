#include <iostream>

std::string string;
bool flag;

void previousVector(std::string prev) {
    flag = false;
    for (int i = prev.size() - 1; i >= 0; i--) {
        if (prev[i] != '1') continue;
        prev[i] = '0';
        for (int j = i + 1; j < prev.size(); j++) prev[j] = '1';
        flag = true;
        break;
    }
    if (flag) {
        std::cout << prev;
    } else {
        std::cout << "-";
    }
}

void nextVector(std::string next) {
    flag = false;
    for (int i = next.size() - 1; i >= 0; i--) {
        if (next[i] != '0') continue;
        next[i] = '1';
        for (int j = i + 1; j < next.size(); j++) next[j] = '0';
        flag = true;
        break;
    }
    if (flag) {
        std::cout << next;
    } else {
        std::cout << "-";
    }
}

int main() {
    freopen("nextvector.in", "r", stdin);
    freopen("nextvector.out", "w", stdout);
    std::cin >> string;
    previousVector(string);
    std::cout << std::endl;
    nextVector(string);
    return 0;
}