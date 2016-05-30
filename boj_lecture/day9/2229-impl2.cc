#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

vector<int> v;
vector<pair<int, int>> vp;
vector<bool> chk;

int main()
{
    cin >> N;

    int tmp;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &tmp);
        v.push_back(tmp);
        vp.emplace_back(v[i], i);
        chk.push_back(false);
    }

    sort(vp.begin(), vp.end());

    int dir = 0, bound = 0;
    int ma = v[0], mi = v[0], sum = 0;

    for (int i = 0; i < N; i++)
    {
        int pos = vp[i].second;
        if (chk[pos])
            continue;

        int dir = 1, rsum = 0, ridx = pos;
        bound = (dir == 1) ? N - 1 : 0;
        for (int j = pos; j != bound; j += dir)
        {
            if (chk[j + dir] || v[j] > v[j + dir])
                break;
            rsum += v[j + dir] - v[j];
            ridx = j + dir;
        }

        dir = -1;
        int lsum = 0, lidx = pos;
        bound = (dir == 1) ? N - 1 : 0;
        for (int j = pos; j != bound; j += dir)
        {
            if (chk[j + dir] || v[j] > v[j + dir])
                break;
            lsum += v[j + dir] - v[j];
            lidx  = j + dir;
        }

        if (lsum < rsum)
        {
            for (int j = pos; j <= ridx; ++j) {
                chk[j] = true;
            }
            sum += rsum;
        }
        else
        {
            for (int j = pos; j >= lidx; --j) {
                chk[j] = true;
            }
            sum += lsum;
        }


    }

    cout << sum;
}