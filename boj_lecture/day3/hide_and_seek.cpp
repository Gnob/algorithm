#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> check(300000), ttime(300000);

int main() {
    int n, k;
    cin >> n >> k;

    queue<int> q;

    q.push(n);
    check[n] = true;

    while (q.empty() == false) {
        int now = q.front(); q.pop();

        if (now == k) {
            cout << ttime[now];
            break;
        }

        int next;

        next = now - 1;
        if (0 <= next && check[next] == false) {
            q.push(next);
            check[next] = true;
            ttime[next] = ttime[now] + 1;
        }

        next = now + 1;
        if (next <= 200000 && check[next] == false) {
            q.push(next);
            check[next] = true;
            ttime[next] = ttime[now] + 1;
        }

        next = 2 * now;
        if (next <= 200000 && check[next] == false) {
            q.push(next);
            check[next] = true;
            ttime[next] = ttime[now] + 1;
        }
    }

    return 0;
}