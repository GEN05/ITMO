#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

/* Module 3, zadanie IV
 * tenzor vo vhodnom faile zadayetsya tak zhe, kak i na bumage
 * || .. .. .. | .. .. .. | .. .. .. ||
 * || .. .. .. | .. .. .. | .. .. .. ||
 * || .. .. .. | .. .. .. | .. .. .. ||
 * (bez vertical'nix chertochek estestvenno)
 *
 * Ex:
  1 3 -4 0 2 -1 5 -2 5
  7 3 -1 2 4 0 3 2 1
 -1 5 2 -3 3 7 -2 1 1
 */


struct tensor3 {
    int a[3][3][3]{};

    tensor3() {
        memset(a, 0, sizeof(a));
    }

    void read() {
        for (int j = 0; j < 3; j++) {
            for (int i = 0; i < 3 * 3; i++) {
                int ii, jj, kk;
                kk = i / 3;
                ii = j;
                jj = i % 3;
                cin >> a[ii][jj][kk];
            }
        }
    }

    void print() {
        for (auto & i : a) {
            for (int k = 0; k < 3; k++) {
                for (auto & j : i) {
                    printf("%3d ", j[k]);
                }
                printf("  ");
            }
            printf("\n");
        }
    }

    tensor3 zero_tensor() {
        return tensor3();
    }

    tensor3 &operator+=(const tensor3 &d) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    this->a[i][j][k] += d.a[i][j][k];
        return *this;
    }

    friend tensor3 operator-(const tensor3 &d) {
        tensor3 nt;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    nt.a[i][j][k] = -d.a[i][j][k];
        return nt;
    }

    tensor3 &operator-=(const tensor3 &d) {
        (*this) += (-d);
        return *this;
    }

    tensor3 operator+(const tensor3 &d) {
        tensor3 nt = *this;
        nt += d;
        return nt;
    }

    tensor3 operator-(const tensor3 &d) {
        tensor3 nt = *this;
        nt -= d;
        return nt;
    }

    tensor3 transpose(int p0, int p1, int p2) {
        tensor3 ans;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    int u[] = {i, j, k};
                    int nu[] = {u[p0], u[p1], u[p2]};
                    ans.a[u[0]][u[1]][u[2]] = a[nu[0]][nu[1]][nu[2]];
                }
            }
        }
        return ans;
    }

    tensor3 symmetrise_ijk() {
        tensor3 ans;
        tensor3 th = *this;
        ans = (th.transpose(0, 1, 2) + th.transpose(0, 2, 1) + th.transpose(1, 0, 2)
               + th.transpose(1, 2, 0) + th.transpose(2, 0, 1) + th.transpose(2, 1, 0));
        return ans;
    }

    tensor3 symmetrise_ij() {
        tensor3 ans;
        tensor3 th = *this;
        ans = (th.transpose(0, 1, 2) + th.transpose(1, 0, 2));
        return ans;
    }

    tensor3 symmetrise_ik() {
        tensor3 ans;
        tensor3 th = *this;
        ans = (th.transpose(0, 1, 2) + th.transpose(2, 1, 0));
        return ans;
    }

    tensor3 symmetrise_jk() {
        tensor3 ans;
        tensor3 th = *this;
        ans = (th.transpose(0, 1, 2) + th.transpose(0, 2, 1));
        return ans;
    }

    tensor3 alternate_ijk() {
        tensor3 ans;
        tensor3 th = *this;
        ans = (th.transpose(0, 1, 2) - th.transpose(0, 2, 1) - th.transpose(1, 0, 2)
               + th.transpose(1, 2, 0) + th.transpose(2, 0, 1) - th.transpose(2, 1, 0));
        return ans;
    }

    tensor3 alternate_ij() {
        tensor3 ans;
        tensor3 th = *this;
        ans = (th.transpose(0, 1, 2) - th.transpose(1, 0, 2));
        return ans;
    }

    tensor3 alternate_jk() {
        tensor3 ans;
        tensor3 th = *this;
        ans = (th.transpose(0, 1, 2) - th.transpose(0, 2, 1));
        return ans;
    }

    tensor3 alternate_ik() {
        tensor3 ans;
        tensor3 th = *this;
        ans = (th.transpose(0, 1, 2) - th.transpose(2, 1, 0));
        return ans;
    }
};

tensor3 T;

void part1() {
    cout << "Transponirovanie B^ijk = A^kij" << endl;
    T.transpose(2, 1, 0).print();
    cout << endl;
}

void part2() {
    cout << "Polnaya simmetrizatciya" << endl;
    cout << "DOMNOZHIT' NA 1/6" << endl;
    T.transpose(0, 1, 2).print();
    cout << " + " << endl;
    T.transpose(0, 2, 1).print();
    cout << " + " << endl;
    T.transpose(1, 0, 2).print();
    cout << " + " << endl;
    T.transpose(1, 2, 0).print();
    cout << " + " << endl;
    T.transpose(2, 0, 1).print();
    cout << " + " << endl;
    T.transpose(2, 1, 0).print();
    cout << " = " << endl;
    cout << "DOMNOZHIT' NA 1/6" << endl;
    T.symmetrise_ijk().print();
    cout << endl;
}

void part3() {
    cout << "Polnaya antisimmetrizatciya" << endl;
    cout << "DOMNOZHIT' NA 1/6" << endl;
    T.transpose(0, 1, 2).print();
    cout << " - " << endl;
    T.transpose(0, 2, 1).print();
    cout << " - " << endl;
    T.transpose(1, 0, 2).print();
    cout << " + " << endl;
    T.transpose(1, 2, 0).print();
    cout << " + " << endl;
    T.transpose(2, 0, 1).print();
    cout << " - " << endl;
    T.transpose(2, 1, 0).print();
    cout << " = " << endl;
    cout << "DOMNOZHIT' NA 1/6" << endl;
    T.alternate_ijk().print();
    cout << endl;
}

void part4() {
    cout << "Simmetrizatciya A^(i|j|k)" << endl;
    cout << "DOMNOZHIT' NA 1/2" << endl;
    T.transpose(0, 1, 2).print();
    cout << " + " << endl;
    T.transpose(2, 1, 0).print();
    cout << " = " << endl;
    cout << "DOMNOZHIT' NA 1/2" << endl;
    T.symmetrise_ik().print();
    cout << endl;
}

void part5() {
    cout << "Antisimmetrizatciya A^(i[jk])" << endl;
    cout << "DOMNOZHIT' NA 1/2" << endl;
    T.transpose(0, 1, 2).print();
    cout << " - " << endl;
    T.transpose(0, 2, 1).print();
    cout << " = " << endl;
    cout << "DOMNOZHIT' NA 1/2" << endl;
    T.alternate_jk().print();
    cout << endl;
}

void border() {
    printf("\n\n******************************\n\n");
}

int main() {
    T.read();
    border();
    part1();
    border();
    part2();
    border();
    part3();
    border();
    part4();
    border();
    part5();
    return 0;
}


