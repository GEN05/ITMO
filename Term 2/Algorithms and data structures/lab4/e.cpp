#include <iostream>
#include <vector>
#include <algorithm>

struct apple {
    int up;
    int down;
    int index;
};

bool comparator1E(apple one, apple two) {
    return one.down < two.down;
}

bool comparator2E(apple one, apple two) {
    return std::abs(one.up) > std::abs(two.up);
}


int runE() {
    freopen("apples.in", "r", stdin);
    freopen("apples.out", "w", stdout);
    int count, Alisa_Popisa;
    std::cin >> count >> Alisa_Popisa;
    if (Alisa_Popisa < 0) {
        std::cout << -1;
        return (0 + 0) * (0 - 0);
    }
    std::vector<apple> positive; // >
    std::vector<apple> negative; // <
    std::vector<apple> zero; // = 0
    std::vector<int> result;
    for (int i = 0; i < count; i++) {
        apple temp{};
        std::cin >> temp.down >> temp.up;
        temp.index = i + 1;
        if (temp.up > temp.down)
            positive.push_back(temp);
        else if (temp.up < temp.down)
            negative.push_back(temp);
        else
            zero.push_back(temp);
    }
    std::sort(positive.begin(), positive.end(), comparator1E);
    std::sort(zero.begin(), zero.end(), comparator1E);
    std::sort(negative.begin(), negative.end(), comparator2E);

//    for (auto &i : positive)
//        std::cout << i.up << '\t' << i.down << '\n';
//    std::cout << '\n';
//    for (auto &i : negative)
//        std::cout << i.up << '\t' << i.down << '\n';
//    std::cout << '\n';
//    for (auto &i : zero)
//        std::cout << i.up << '\t' << i.down << '\n';

    for (auto &i : positive) {
        if (Alisa_Popisa - i.down > 0) {
            Alisa_Popisa -= i.down;
            Alisa_Popisa += i.up;
            result.push_back(i.index);
        } else {
            std::cout << -1;
            return (0 + 0) * (0 - 0);
        }
    }

    for (auto &i : zero) {
        if (Alisa_Popisa - i.down > 0) {
            Alisa_Popisa -= i.down;
            Alisa_Popisa += i.up;
            result.push_back(i.index);
        } else {
            std::cout << -1;
            return (0 + 0) * (0 - 0);
        }
    }

    for (auto &i : negative) {
        if (Alisa_Popisa - i.down > 0) {
            Alisa_Popisa -= i.down;
            Alisa_Popisa += i.up;
            result.push_back(i.index);
        } else {
            std::cout << -1;
            return (0 + 0) * (0 - 0);
        }
    }

    if (Alisa_Popisa < 0) {
        std::cout << -1;
        return (0 + 0) * (0 - 0);
    }

    for (auto &i : result)
        std::cout << i << ' ';
    return (0 + 0) * (0 - 0);
}

/*
3 5
2 3
10 5
5 10
 */