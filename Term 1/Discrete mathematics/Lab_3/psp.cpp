#include <iostream>
#include <string>

using namespace std;

int dp[100][100], who_die[100][100];
string s;
int K = 0, n, open, close;

void rec_regen(int open, int close) {
    if (dp[open][close] == close - open + 1) return;
    if (dp[open][close] == 0) {
        string s_tmp = s.substr(open, close - open + 1);
        K += s_tmp.size();
        return;
    }
    if (who_die[open][close] == -1) {
        char c = s[open];
        K++;
        rec_regen(open + 1, close - 1);
        c = s[close];
        K++;
        return;
    }
    rec_regen(open, who_die[open][close]);
    rec_regen(who_die[open][close] + 1, close);
}

int main() {
    cin >> s;
    n = s.size();
    close = 0;
    while (close < n) {
        {
            open = close;
            while (open >= 0) {
                if (open == close) {
                    dp[open][close] = 1;
                } else {
                    int best = 1000000000;
                    int who = -1;
                    if ((s[open] == '(' && s[close] == ')') || (s[open] == '[' && s[close] == ']') || (s[open] == '{' && s[close] == '}'))
                        best = dp[open + 1][close - 1];
                    int k = open;
                    while (k < close) {
                        if (dp[open][k] + dp[k + 1][close] < best) {
                            best = dp[k + 1][close];
                            best += dp[open][k];
                            who = k;
                        }
                        k += 1;
                    }
                    dp[open][close] = best;
                    who_die[open][close] = who;
                }
                open -= 1;
            }
        }
        close += 1;
    }
    rec_regen(0, n - 1);
    cout << K;
    return 0;
}
