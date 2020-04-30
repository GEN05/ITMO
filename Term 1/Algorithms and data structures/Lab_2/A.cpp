#include <iostream>
#include <vector>

std::vector<int> a;
int n, p, min, temp, buf, k = 0;

int main() {
    scanf("%d", &n);
    for (unsigned int i = 0; i < n; i++) {
        scanf("%d", &p);
        if (p == 1) {
            k++;
            scanf("%d", &temp);
            if (a.empty()) {
                a.push_back(temp);
            } else if (a[k - 2] < temp){
                buf = a[k - 2];
                a.push_back(buf);
            } else {
                a.push_back(temp);
            }
        } else if (p == 2) {
            a.pop_back();
            k--;
        } else {
            printf("%d", a[a.size() - 1]);
            printf("\n");
        }
        /*for (int j = 0; j < a.size(); j++) {
            std::cout << a[j] << " ";
        }
        std::cout << std::endl;*/
    }
    return 0;
}