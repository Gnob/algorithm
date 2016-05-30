#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

vector<int> v;
vector<pair<int, int>> vp;
vector<bool> chk;


int checkDirection(int curPos) {
    if (N == 1)
        return 0;
    if (curPos == N - 1 && v[curPos] < v[curPos - 1])
        return -1;

    else if (curPos == 0 && v[curPos] < v[curPos + 1])
        return 1;

    int dis = 1;
    while (curPos + dis < N && curPos - dis >= 0 && v[curPos - dis] == v[curPos + dis])
        dis++;

    if (curPos + dis == N && curPos - dis != -1)
        return -1;
    else if (curPos + dis != N && curPos - dis == -1)
        return 1;
    else if (curPos + dis == N && curPos - dis == -1)
        return 0;

    if (v[curPos - dis] < v[curPos + dis])
        return 1;
    else
        return -1;
}

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
        chk[pos] = true;

        dir = checkDirection(pos);
        if (dir == 0)
            continue;

        bound = (dir == 1) ? N - 1 : 0;
        for (int j = pos; j != bound; j += dir)
        {
            if (chk[j + dir] || v[j] > v[j + dir])
                break;
            sum += v[j + dir] - v[j];
            chk[j + dir] = true;
        }
    }

    cout << sum;
}