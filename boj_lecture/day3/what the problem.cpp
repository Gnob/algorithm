#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
struct vtx {
    int v;
    char m;
    vtx *p;
};

vector<bool> check(300000);

int main() {
    int t, ori, res;
    cin >> t;

    while (t--) {
        cin >> ori >> res;

        queue<vtx> q;

        q.push(vtx{ori, ' ', NULL});
        check[ori] = true;

        while (! q.empty()) {
            vtx nowVtx = q.front();
            q.pop();

            if (nowVtx.v == res) {
                cout << "ans in";
                printf("\n");
                vtx *vp = &nowVtx;
                string ans = "";
                while (vp->v != ori) {
                    ans += vp->m;
                    vp = vp->p;
                    cout << vp << " ";
                    printf("\n");
                    cin >> ans;
                }
                cout << ans;
                break;
            }

            int next;

            next = (nowVtx.v * 2) % 10000;
            if (next < 10000 && check[next] == false) {
                q.push(vtx{next, 'D', &nowVtx});
                cout << q.back().p << endl;
                check[next] = true;
            }

            next = nowVtx.v - 1;
            if (next == -1) next = 9999;
            if (0 <= next && check[next] == false) {
                q.push(vtx{next, 'S', &nowVtx});
                check[next] = true;
            }


            next = (nowVtx.v % 1000) * 10 + nowVtx.v / 1000;
            if (next < 10000 && check[next] == false) {
                q.push(vtx{next, 'L', &nowVtx});
                check[next] = true;
            }

            next = nowVtx.v / 10 + (nowVtx.v % 10) * 1000;
            if (next <= 200000 && check[next] == false) {
                q.push(vtx{next, 'R', &nowVtx});
                check[next] = true;
            }
        }

    }
    return 0;
}