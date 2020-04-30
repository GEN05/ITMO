#include <iostream>
#include <vector>

std::vector<long long> partition;
std::string string, temp;
long long i, sum;

void nextPartition() {
    partition[partition.size() - 1]--;
    partition[partition.size() - 2]++;
    if (partition[partition.size() - 2] > partition[partition.size() - 1]) {
        partition[partition.size() - 2] += partition[partition.size() - 1];
        partition.pop_back();
    } else {
        while (partition[partition.size() - 2] * 2 <= partition[partition.size() - 1]) {
            partition.push_back(partition[partition.size() - 1] - partition[partition.size() - 2]);
            partition[partition.size() - 2] = partition[partition.size() - 3];
        }
    }
    std::cout << temp;
    for (long long k = 0; k < partition.size() - 1; k++) {
        std::cout << partition[k] << "+";
    }
    std::cout << partition[partition.size() - 1];
    std::cout << "\n";
}

int main() {
    //freopen("nextpartition.in","r",stdin);
    //freopen("nextpartition.out","w",stdout);
    std::cin >> string;
    while (string[i] != '=') {
        temp += string[i];
        i++;
    }
    temp += '=';
    i++;
    while (i < string.length()) {
        sum = 0;
        while (!(string[i] == '+' || string.length() <= i)) {
            sum = sum * 10 + (long long) string[i] - 48;
            i++;
        }
        partition.push_back(sum);
        i++;
    }
    if (partition.size() != 1) {
        nextPartition();
    } else {
        std::cout << "No solution";
    }
    return 0;
}
