#include <iostream>

using namespace std;

/* Punkt 1.  Schitaem tenzor v novom bazise.
 * formula:
 * A'[a][b][c][d] = sum_i sum_j sum_k sum_l T[a][i] * T[b][j] * T[c][k] * T[d][l] * A[i][j][k][l]
 * a, b - indexi sverxy, c, d - snizu
 *
 * A: matrica tenzora
 *     _____l=0____________l=1____
 *     ||              |        ||
 *     ||A[i][j][0][0] |        ||
 * k=0 ||              |        ||
 *     ||              |        ||
 *     ||-----------------------||
 *     ||              |        ||
 *     ||A[i][j][1][0] |        ||
 * k=1 ||              |        ||
 *     ||_____________ |________||
 *
 * k, l - vneshnie indexy
 * i, j - vnutrennie indexy (i - stroki, j - stolbci)
 *
 * T: matrica perexoda v noviy basis
 * zadaetsya kak obichno, i - stroki, j - stolbci
 *
 * --------------
 * Punkt 2. Schitaem svertku tenzora
 * formula:
 * Summiruem po povtoruaushimsya indexam, iz nepovtoryaushixsya obrazuem matricy-svertku.
 *
 * primer 1:
 * Schitaem svertku A[i][j][i][k]
 * Sv[j][k] = A[0][j][0][k] + A[1][j][1][k]
 *
 * primer 2:
 * Schotaem svertku A[i][i][j][j]
 * Sv = A[0][0][0][0] + A[0][0][1][1] + A[1][1][0][0] + A[1][1][1][1]
 * ----------------
 *
 * */

int A[2][2][2][2];
int T[2][2];

void init() {
    A[0][0][0][0] = 5;
    A[0][1][0][0] = -6;
    A[1][0][0][0] = 2;
    A[1][1][0][0] = 6;

    A[0][0][0][1] = 4;
    A[0][1][0][1] = 6;
    A[1][0][0][1] = 1;
    A[1][1][0][1] = 4;

    A[0][0][1][0] = 0;
    A[0][1][1][0] = -1;
    A[1][0][1][0] = 0;
    A[1][1][1][0] = 2;

    A[0][0][1][1] = -3;
    A[0][1][1][1] = 0;
    A[1][0][1][1] = 0;
    A[1][1][1][1] = 5;

    T[0][0] = 1;
    T[0][1] = 2;
    T[1][0] = 1;
    T[1][1] = 1;
}

void part1(int a, int b,
           int c, int d) //pereveod v noviu basis
{
    cout << "Schitaem element A'[" << a << "][" << b << "][" << c << "][" << d << "] v novom bazise" << endl;
    int ans = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 2; l++) {
                    int add = T[a][i] * T[b][j] * T[c][k] * T[d][l] * A[i][j][k][l];
                    ans += add;
                    cout << T[a][i] << " * " << T[b][j] << " * " << T[c][k] << " * " << T[d][l] << " * "
                         << A[i][j][k][l] << "  ( " << add << " )" << endl;
                    cout << "+" << endl;
                }
    cout << " = " << ans << endl;
    cout << endl;
}


void part2() //svertka
{
    cout << "Svertka 1: a^ij_ki" << endl;
    for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++) {
            cout << "j = " << j << " ; k = " << k << " value = ";
            for (int i = 0; i < 2; i++)
                cout << A[i][j][k][i] << " + ";
            cout << endl;
        }
    cout << endl;

    cout << "Svertka 2: a^ij_kj" << endl;
    for (int i = 0; i < 2; i++)
        for (int k = 0; k < 2; k++) {
            cout << "i = " << i << " ; k = " << k << " value = ";
            for (int j = 0; j < 2; j++)
                cout << A[i][j][k][j] << " + ";
            cout << endl;
        }
    cout << endl;

    cout << "Svertka 3: a^ij_ij" << endl;
    cout << " value = ";
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cout << A[i][j][i][j] << " + ";
    cout << endl;
    cout << endl;

    cout << "Svertka 4: a^ij_ji" << endl;
    cout << " value = ";
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cout << A[i][j][j][i] << " + ";
    cout << endl;
    cout << endl;
}

int main() {
    init();
    part1(1, 0,
          0, 1);
    part1(1, 1,
          0, 0);
    part2();
    return 0;
}