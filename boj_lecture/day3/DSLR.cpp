#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> p(300000);
vector<char> m(300000);
vector<bool> check(300000);

int main() {
    int t, ori, res;
    cin >> t;

    while (t--) {
        p.assign(300000, 0);
        m.assign(300000, ' ');
        check.assign(300000, false);

        cin >> ori >> res;

        queue<int> q;

        q.push(ori);
        check[ori] = true;

        while (! q.empty()) {
            int now = q.front();
            q.pop();

            int next;

            next = (now * 2) % 10000;
            if (next < 10000 && check[next] == false) {
                q.push(next);
                p[next] = now;
                m[next] = 'D';
                check[next] = true;
            }

            next = now - 1;
            if (next == -1) next = 9999;
            if (0 <= next && check[next] == false) {
                q.push(next);
                p[next] = now;
                m[next] = 'S';
                check[next] = true;
            }

            next = (now % 1000) * 10 + now / 1000;
            if (next < 10000 && check[next] == false) {
                q.push(next);
                p[next] = now;
                m[next] = 'L';
                check[next] = true;
            }

            next = now / 10 + (now % 10) * 1000;
            if (next <= 200000 && check[next] == false) {
                q.push(next);
                p[next] = now;
                m[next] = 'R';
                check[next] = true;
            }
        }

        string ans = "";
        while (res != ori) {
            ans += m[res];
            res = p[res];
        }
        reverse(ans.begin(), ans.end());
        cout << ans;

        cout << "\n";

    }
    return 0;
}