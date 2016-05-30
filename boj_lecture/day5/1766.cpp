
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> tree(1000000);
int idx = 0;

int top() {
    return tree[1];
}

void push(int x) {
    tree[++idx] = x;

    int now = idx;
    while (now != 1 && tree[now/2] > tree[now]) {
        swap(tree[now/2], tree[now]);
        now /= 2;
    }
}

void pop() {
    int now = 1, child;
    tree[now] = tree[idx--];
    tree[idx + 1] = 0;

    while (now < idx) {
        child = 2 * now;
        if (child > idx) break;
        else if (idx != child && tree[child + 1] < tree[child]) child++;

        if (tree[now] > tree[child]) {
            swap(tree[now], tree[child]);
            now = child;
        }
        else
            break;
    }
}

int main(void) {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> v(M);
    vector<int> cnt(N + 1), ind(N + 1);

    for (int i = 0; i < M; i++) {
        v.emplace_back(make_pair(0, 0));
        scanf("%d %d", &v[i].first, &v[i].second);
    }

    sort(v.begin(), v.end());

    for (auto k : v) {
        ind[k.second]++;
        cnt[k.first]++;
    }

    int starter = 0;
    for (int i = 1; i <= N; i++) {
        cnt[i] += cnt[i - 1];
        if (ind[i] == 0) push(i);
    }


    while (idx > 0) {
        int now = top(); pop();
        printf("%d ", now);
        for (int i = cnt[now - 1]; i < cnt[now]; i++) {
            ind[v[i].second]--;
            if (ind[v[i].second] == 0) {
                push(v[i].second);
            }
        }
    }
}