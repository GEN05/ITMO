#include <iostream>
#include <vector>

int n;
int set1, set2;
std::vector<int> a;
std::vector<int> min;
std::vector<int> max;
std::vector<int> count;
std::string s;

void uni(int uni_set1, int uni_set2) {
    while (uni_set1 != a[uni_set1]) {
        uni_set1 = a[uni_set1];
    }
    while (uni_set2 != a[uni_set2]) {
        uni_set2 = a[uni_set2];
    }
    if (count[uni_set2] < count[uni_set1]) {
        std::swap(uni_set1, uni_set2);
    }
    if (uni_set1 != uni_set2) {
        count[uni_set2] += count[uni_set1];
    }
    max[uni_set2] = std::max(max[uni_set1], max[uni_set2]);
    min[uni_set2] = std::min(min[uni_set1], min[uni_set2]);
    a[uni_set1] = uni_set2;
}

int get(int set) {
    if (a[set] != set) {
        set = get(a[set]);
    }
    return set;
}

int main() {
    std::cin >> n;
    a.resize(n + 1), min.resize(n + 1), max.resize(n + 1), count.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = i;
        min[i] = i;
        max[i] = i;
        count[i] = 1;
    }
    while (std::cin >> s) {
        if (s == "union") {
            std::cin >> set1 >> set2;
            uni(set1, set2);
        }
        if (s == "get") {
            int set;
            std::cin >> set;
            std::cout << min[get(set)] << " " << max[get(set)] << " " << count[get(set)] << std::endl;
        }
    }
    return 0;
}