#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> edge;
vector<int> res;

void find(int l, int r, int v) {
    while (l < r) {
        int mid = (l + r) / 2;
        if (edge[v - 1][res[mid] - 1] == 1) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    res.insert(res.begin() + l, v);
}

void makeCycle(int a, int b) {
    bool cycle = false;
    while (!cycle) {
        cycle = true;
        for (int i = a + 1; i < b; i++) {
            for (int j = 1; j < a + 1; j++) {
                if (edge[res[i] - 1][res[j] - 1] == 0) {
                    continue;
                }
                vector<int>save(res.begin() + a + 1, res.begin() + i + 1);

                for (int k = 0; k >= j - a; k--) {
                    res[k + i] = res[k + a];
                }
                for (int k = 0; k < i - a; k++) {
                    res[k + j] = save[k];
                }

                a = i;
                cycle = false;
                break;
            }
            if (!cycle) {
                break;
            }
        }
    }
}

void cycle() {
    int tmp = edge.size() - 1;
    while (tmp > 0 && edge[res[tmp] - 1][res[0] - 1] == 0) {
        tmp--;
    }
    if (tmp != edge.size() - 1) {
        makeCycle(tmp, edge.size());
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    int n;
    cin >> n;
    edge.resize(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            string tmp;
            cin >> tmp;
            for (int j = 0; j < i; j++) {
                if ((int) tmp[j] - 48 == 1) {
                    edge[i][j] = 1;
                    edge[j][i] = 0;
                } else {
                    edge[i][j] = 0;
                    edge[j][i] = 1;
                }
            }
        }
    }

    for (int i = 1; i < n + 1; i++) {
        find(0, i - 1, i);
    }

    cycle();

    /* for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
             cout << edge[i][j] << " ";
         }
         cout << endl;
     }*/
}
