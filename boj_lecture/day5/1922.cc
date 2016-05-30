#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<pair<int, int>> tree(1000000);
int idx = 0;

pair<int, int> &top() {
    return tree[1];
}

void push(pair<int, int> &x) {
    tree[++idx] = x;

    int now = idx;
    while (now != 1 && tree[now/2].second > tree[now].second) {
        swap(tree[now/2], tree[now]);
        now /= 2;
    }
}

void pop() {
    int now = 1, child;
    tree[now] = tree[idx--];
    while (now < idx) {
        child = 2 * now;
        if (child > idx) break;
        else if (idx != child && tree[child + 1].second < tree[child].second) child++;

        if (tree[now].second > tree[child].second) {
            swap(tree[now], tree[child]);
            now = child;
        }
        else
            break;
    }
}

vector<pair<int, int>> v[1001];
vector<bool> c(1001);

int main(void) {
    int N, M;

    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        v[x].push_back(make_pair(y, w));
        v[y].push_back(make_pair(x, w));
    }

    c[1] = true;

    for (auto &e : v[1]) {
        push(e);
    }

    int ans = 0;

    while (idx > 0) {
        pair<int, int> now = top(); pop();
        if (c[now.first] == false) {
            ans += now.second;
            c[now.first] = true;

            for (auto &e : v[now.first]) {
                push(e);
            }
        }
    }

    cout << ans;
}