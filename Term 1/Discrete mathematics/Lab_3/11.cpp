#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> a;
std::vector<int> partition;
int n;

void generatePartition(std::vector<int> partitionTemp, int number) {
    if (number == n) {
        a.push_back(partitionTemp);
        return;
    }
    generatePartition(partitionTemp, number + 1);
    partitionTemp.push_back(number + 1);
    generatePartition(partitionTemp, number + 1);
}

int main() {
    freopen("subsets.in", "r", stdin);
    freopen("subsets.out", "w", stdout);
    std::cin >> n;
    generatePartition(partition, 0);
    std::sort(a.begin(), a.end());
    for (auto &i : a) {
        for (int j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}