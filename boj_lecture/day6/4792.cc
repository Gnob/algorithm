#include <iostream>
#include <vector>
#include <algorithm>

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
    int from, to, color;
};

bool cmp(const Edge &a, const Edge &b) {
    return a.color < b.color;
}

Edge e[1000000];

int main(void) {
    int N = 1, M = 1, K = 1;

    while (true) {
        scanf("%d %d %d", &N, &M, &K);

        if (N == 0 && M == 0 && K == 0)
            break;

        for (int i = 0; i < M; i++) {
            int x, y;
            char c;
            scanf(" %c %d %d", &c, &e[i].from, &e[i].to);

            if (c == 'B')
                e[i].color = 1;
            else
                e[i].color = 0;

        }

        sort(e, e + M, cmp);

        for (int k = 1; k <= N; ++k) {
            p[k] = k;
        }

        int minimum = 0;

        for (int j = 0; j < M; ++j) {
            int x = find(e[j].from);
            int y = find(e[j].to);

            if (x != y) {
                if (e[j].color == 1) minimum++;
                unionSet(x, y);
            }
        }

        reverse(e, e + M);

        for (int k = 1; k <= N; ++k) {
            p[k] = k;
        }

        int maximum = 0;

        for (int j = 0; j < M; ++j) {
            int x = find(e[j].from);
            int y = find(e[j].to);

            if (x != y) {
                if (e[j].color == 1) maximum++;
                unionSet(x, y);
            }
        }

        if (minimum <= K && K <= maximum)
            printf("1\n");
        else
            printf("0\n");
    }
}