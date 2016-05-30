#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int p[10001];

int find(int x) {
    if (p[x] == x) {
        return x;
    }
    else {
        return p[x] = find(p[x]);
    }
}

void unionSet(int x, int y) {
    p[x] = y;
}

struct Edge {
    int from, to, cost;
};

bool cmp(const Edge &a, const Edge &b) {
    return a.cost < b.cost;
}

Edge e[100000];

int main(void) {
    int V, E;

    scanf("%d %d", &V, &E);

    for (int i = 0; i < E; i++) {
        int x, y, w;
        scanf("%d %d %d", &e[i].from, &e[i].to, &e[i].cost);
    }

    sort(e, e + E, cmp);

    for (int k = 1; k <= V; ++k) {
        p[k] = k;
    }

    int ans = 0;

    for (int j = 0; j < E; ++j) {
        int x = find(e[j].from);
        int y = find(e[j].to);

        if (x != y) {
            ans += e[j].cost;
            unionSet(x, y);
        }
    }

    cout << ans;
}