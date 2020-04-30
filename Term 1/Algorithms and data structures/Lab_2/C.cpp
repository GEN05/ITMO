#include <iostream>
#include <vector>

std::vector<int> a;
int n, p, j;

int main() {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> p;
        if (p == 1) {
            std::cin >> p;
            a.push_back(p);
            //std::cout << "add " << p << std::endl;
        } else if (p == 2) {
            //std::cout << "delFirst" << std::endl;
            a.erase(a.begin());
        } else if (p == 3) {
            a.pop_back();
            //std::cout << "delBack" << std::endl;
        } else if (p == 4) {
            std::cin >> p;
            j = 0;
            while (a[j] != p) {
                j++;
            }
            std::cout << j << std::endl;
            //std::cout << " Size" << std::endl;
        } else {
            std::cout << a[0] << std::endl;
            //std::cout << " First" << std::endl;
        }
    }
    return 0;
}