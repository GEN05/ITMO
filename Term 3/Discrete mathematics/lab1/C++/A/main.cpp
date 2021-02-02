//
// Created by 2000a on 22.12.2020.
//
#include <iostream>
#include <deque>
#include <algorithm>

void write_deque(const std::deque<int>& deque) {
    for (int i : deque)
        std::cout << i + 1 << " ";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie();
    int n = 0;
    std::cin >> n;
    int graph[n][n];
    for (int i = 1; i < n; i++) {
        std::string string;
        std::cin >> string;
        for (int j = 0; j < string.length(); j++) {
            if (string[j] - 48 == 0) {
                graph[i][j] = 0;
                graph[j][i] = 0;
            } else if (string[j] - 48 == 1) {
                graph[i][j] = 1;
                graph[j][i] = 1;
            }
        }
    }
    std::deque<int> deque;
    for (int i = 0; i < n; i++)
        deque.push_back(i);
    for (int i = 0; i < n * (n - 1); ++i) {
        if (graph[deque[0]][deque[1]] == 0) {
            int j = 2;
            while (graph[deque[0]][deque[j]] == 0 || graph[deque[1]][deque[j + 1]] == 0)
                j++;
            if (j == n - 1) {
                j = 2;
                while (graph[deque[0]][deque[j]] == 0)
                    j++;
            }
            std::reverse(deque.begin() + 1, deque.begin() + j + 1);
        }
        deque.push_back(deque.front());
        deque.pop_front();
    }
    write_deque(deque);
    return 0;
}