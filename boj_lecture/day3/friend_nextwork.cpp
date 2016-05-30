#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

vector<int> p(200000);

int findSet(int x) {
    if (p[x] == x) {
        return x;
    }
    else {
        vector<int> v;
        while (p[x] != x) {
            v.push_back(x);
            x = p[x];
        }

        for (auto k : v) {
            p[k] = x;
        }

        return x;
    }
}
/*
 int findSet(int x) {
    if (p[x] == x) {
        return x;
    }
    else {
        vector<int> v;
        while (p[x] != x) {
            v.push_back(x);
            x = p[x];
        }

        for (auto k : v) {
            p[k] = x;
        }

        return x;
    }
}
 */

void unionSet(int a, int b) {
    p[findSet(b)] = findSet(a);
}

const int countSet(const int x, const int n) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (findSet(x) == findSet(i)) cnt++;
    }
    return cnt;
}

int getIdx(vector<string> &cv, char *str) {
    int idx = 0;
    string tmp = string(str, strlen(str));
    for (idx = 0; idx < cv.size(); idx++) {
        if (tmp.compare(cv[idx]) == 0)
            break;
    }

    if (idx == cv.size()) {
        p[idx] = idx;
        cv.push_back(str);
    }

    return idx;
}

int main() {
    int N, T;

    cin >> T;

    while (T--) {
        cin >> N;

        vector<string> v;

        for (int i = 0; i < N; ++i) {
            char buf[80];
            int a, b;

            scanf("%s", buf);
            a = getIdx(v, buf);

            scanf("%s", buf);
            b = getIdx(v, buf);

            unionSet(a, b);
            printf("%d\n", countSet(a, v.size()));
        }
    }

    return 0;
}