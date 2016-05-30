#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge {
    int from, to, cost;
};

bool cmp(const Edge &a, const Edge &b) {
    return a.cost < b.cost;
}

int main() {
    int T;

    scanf("%d", &T);

    while(T--) {
        int N, M, W;
        scanf("%d %d %d", &N, &M, &W);

        int a[501][501];
        vector<int> d(N + 1);
        d.assign(N + 1, INT32_MAX);

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                a[i][j] = INT32_MAX;
            }
        }

        for (int i = 0; i < M; i++) {
            int f, t, c;
            scanf("%d %d %d", &f, &t, &c);
            a[f][t] = min(a[f][t], c);
            a[t][f] = min(a[t][f], c);
        }
        for (int i = 0; i < W; i++) {
            int f, t, c;
            scanf("%d %d %d", &f, &t, &c);
            a[f][t] = min(a[f][t], -c);
        }

        vector<Edge> e;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (a[i][j] < INT32_MAX) {
                    e.push_back(Edge{i, j, a[i][j]});
                }
            }
        }

        sort(e.begin(), e.end(), cmp);

        d[1] = 0;
        bool isCycle = false;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < e.size(); j++) {
                if(d[e[j].from] != INT32_MAX && d[e[j].to] > d[e[j].from] + e[j].cost) {
                    d[e[j].to] = d[e[j].from] + e[j].cost;
                    if (i == N)
                        isCycle = true;
                }
            }
        }

        cout << (isCycle ? "YES" : "NO") << "\n";
    }

}