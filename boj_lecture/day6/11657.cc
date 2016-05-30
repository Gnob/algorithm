#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

struct Edge {
    int from, to, cost;
};

int d[501];

int main(void) {
    int V, E;

    scanf("%d %d", &V, &E);

    vector<Edge> e(E);

    for (int i = 0; i < E; i++) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        e.push_back(Edge{x, y, w});
    }

    for (int k = 1; k <= V; ++k) {
        d[k] = INT32_MAX;
    }

    d[1] = 0;

    bool isCycle = false;

    for (int i = 1; i <= V; ++i) {
        for (int j = 0; j < e.size(); ++j) {
            if (d[e[j].from] != INT32_MAX && d[e[j].to] > d[e[j].from] + e[j].cost) {
                d[e[j].to] = d[e[j].from] + e[j].cost;
                if (i == V) {
                    isCycle = true;
                    break;
                }
            }
        }
    }

    if (isCycle)
        cout << -1;
    else {
        for (int i = 2; i <= V; ++i) {
            if (d[i] == INT32_MAX) printf("-1\n");
            else printf("%d\n", d[i]);
        }
    }
}
