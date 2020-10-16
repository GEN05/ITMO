#include <iostream>
#include <cmath>
#include <algorithm>

struct paper {
    int count;
    int price;
    double utilPrice;
};

bool comparatorC(paper one, paper two) {
    return one.utilPrice < two.utilPrice;
}

int getAnswer(paper Paper[], int i, int n) {
    if (n == 0)
        return 0;
    int minPrice = Paper[i].price * (n / Paper[i].count);
    return minPrice + std::min(Paper[i].price, getAnswer(Paper, i + 1, n % Paper[i].count));
}

int runC() {
    //freopen("printing.in", "r", stdin);
    //freopen("printing.out", "w", stdout);
    int n;
    std::cin >> n;
    paper Paper[7];
    for (int i = 0; i < 7; i++) {
        Paper[i].count = std::pow(10, i);
        std::cin >> Paper[i].price;
        Paper[i].utilPrice = (double) Paper[i].price / Paper[i].count;
    }
    std::cout << '\n';
    for (auto & j : Paper)
        std::cout << j.price << "\t" << j.count << '\t' << j.utilPrice << '\n';
    std::sort(Paper, Paper + 7, comparatorC);
    std::cout << '\n';
    for (auto & j : Paper)
        std::cout << j.price << "\t" << j.count << '\t' << j.utilPrice << '\n';
    std::cout << getAnswer(Paper, 0, n);
    return 0;
}