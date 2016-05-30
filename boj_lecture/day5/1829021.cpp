	
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main(void) {
    int N, M;
    cin >> N >> M;
 
    vector<pair<int, int>> v(M);
    vector<int> cnt(N + 1), ind(N + 1), q(100000);
     
    for (int i = 0; i < M; i++) {
        v.emplace_back(make_pair(0, 0));
        scanf("%d %d", &v[i].first, &v[i].second);
    }
     
    sort(v.begin(), v.end());
     
    for (auto k : v) {
        ind[k.second]++;
        cnt[k.first]++;
    }
     
    int head, tail;
    head = tail = 0;
     
    int starter = 0;
    for (int i = 1; i <= N; i++) {
        cnt[i] += cnt[i - 1];
        if (ind[i] == 0) q[head++] = i;
    }
     
     
    while (head != tail) {
        int now = q[tail++];
        printf("%d ", now);
        for (int i = cnt[now - 1]; i < cnt[now]; i++) {
            ind[v[i].second]--;
            if (ind[v[i].second] == 0) {
                q[head++] = v[i].second;
            }
        }
    }        
}