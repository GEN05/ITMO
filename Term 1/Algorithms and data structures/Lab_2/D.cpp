#include <iostream>
#include <list>

std::list<int> a;
std::list<int> b;
int n, p, temp;
char c;

int main() {
    std::ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    for (unsigned int i = 0; i < n; i++) {
        scanf("%s", &c);
        if  (c == '+') {
            scanf("%d", &p);
            b.push_back(p);
        } else if (c == '-') {
            printf("%d", a.front());
            printf("\n");
            a.pop_front();
        } else if (c == '*') {
            scanf("%d", &p);
            b.push_front(p);
        }
        if (b.size() > a.size()) {
            temp = b.front();
            b.pop_front();
            a.push_back(temp);
        }
    }
    return 0;
}