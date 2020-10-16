#include <iostream>
#include <vector>

typedef long long int ll;

void matrixMultiplication(std::vector<std::vector<ll>> &matrix, std::vector<std::vector<ll>> &res) {
    for (ll i = 0; i < 4; i++)
        for (ll j = 0; j < 4; j++)
            for (ll k = 0; k < 4; k++)
                res[i][j] += matrix[i][k] * matrix[k][j];
    for (auto &i : res)
        for (auto &j : i)
            j %= 2;
}

bool equalsMatrix(std::vector<std::vector<ll>> &A, std::vector<std::vector<ll>> &B) {
    for (ll i = 0; i < 4; i++)
        for (ll j = 0; j < 4; j++)
            if (A[i][j] != B[i][j])
                return false;
    return true;
}

void generate(std::vector<std::vector<ll>> &b, std::vector<ll> &a, ll level) {
    if (level < 16) {
        a.push_back(0);
        generate(b, a, ++level);
        a.pop_back();
        a.push_back(1);
        generate(b, a, level);
        a.pop_back();
    } else
        b.push_back(a);
}


int runI() {
    //freopen("sqroot.in", "r", stdin);
    //freopen("sqroot.out", "w", stdout);
    //std::ios_base::sync_with_stdio(false);
    //std::cin.tie(nullptr);
    std::vector<std::vector<ll>> matrix(4);
    std::vector<std::vector<ll>> res(4);
    std::vector<std::vector<ll>> answer(4);
    std::vector<std::vector<ll>> allVectors;
    std::vector<ll> garbage;
    for (auto &i : matrix)
        i.resize(4);
    for (auto &i : res)
        i.resize(4);
    for (auto &i : answer)
        i.resize(4);
    for (auto &i : answer)
        for (auto &j : i)
            std::cin >> j;
    generate(allVectors, garbage, 0);

    for (auto &allVector : allVectors) {
        ll bit = 0;
        for (auto &i : matrix)
            for (ll &j : i) {
                j = allVector[bit];
                bit++;
            }
        matrixMultiplication(matrix, res);
        if (equalsMatrix(res, answer)) {
            for (auto &i : matrix) {
                for (auto &j : i)
                    std::cout << j << ' ';
                std::cout << '\n';
            }
            return 0;
//            flag = true;
        }
    }
//    if (!flag)
    std::cout << "NO SOLUTION";
    return 0;
}