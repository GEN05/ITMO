#include <iostream>
#include <vector>

std::vector<int> a;
std::vector<int> quantity;
std::vector<int> experience;
int n, m, x, v, y, sum;
char in[4];

void join(int player_x, int player_y) {
    while (player_x != a[player_x]) {
        player_x = a[player_x];
    }
    while (player_y != a[player_y]) {
        player_y = a[player_y];
    }
    if (quantity[player_x] > quantity[player_y]) {
        std::swap(player_x, player_y);
    }
    if (player_x != player_y) {
        experience[player_x] -= experience[player_y];
        a[player_x] = player_y;
        quantity[player_y] = std::max(quantity[player_x], quantity[player_y]);
        quantity[player_x] = 0;
    }
}

void add(int player_x, int add_v) {
    while (player_x != a[player_x]) {
        player_x = a[player_x];
    }
    experience[player_x] += add_v;
}

void get(int player_x) {
    sum = 0;
    while (player_x != a[player_x]) {
        sum += experience[player_x];
        player_x = a[player_x];
    }
    printf("%d", sum + experience[player_x]);
    printf("\n");
}

int main() {
    std::ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    scanf("%d", &m);
    a.resize(n + 1), quantity.resize(n + 1), experience.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = i;
        quantity[i] = 1;
        experience[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        scanf("%s", in);
        if (in[0] == 'j') {
            scanf("%d", &x);
            scanf("%d", &y);
            join(x, y);
        }
        if (in[0] == 'a') {
            scanf("%d", &x);
            scanf("%d", &v);
            add(x, v);
        }
        if (in[0] == 'g') {
            scanf("%d", &x);
            get(x);
        }
    }
    return 0;
}