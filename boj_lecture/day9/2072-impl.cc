31
3 3
2 3
3 4
2 2
3 2
3 1
3 5
2 4
2 5
2 1
1 5
4 1
4 5
5 5 
1 4 
5 1
1 3 
1 1 
5 3 
6 1 
1 2 
5 4 
4 2 
4 4 
4 3
10 10
3 6
11 11
4 7
12 12
5 8


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Stone {
    int color, seq;
};

Stone a[21][21];

bool cmp(const Stone &a, const Stone &b)
{
    return a.seq < b.seq;
}

int main()
{
    int N; cin >> N;


    for (int i = 1; i <= 20; i++)
    {
        for (int j = 1; j <= 20; j++)
        {
            a[i][j].color = -1;
            a[i][j].seq = -1;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x][y].color = i % 2;
        a[x][y].seq = i;
    }

    int minSeq = 101;
    int xst, xed;
    for (int i = 1; i <= 20; i++)
    {
        xst = xed = 1;
        for (int j = 2; j <= 20; j++)
        {
            if (a[i][j].color > -1 && a[i][j].color == a[i][j - 1].color)
            {
                xed = j;
                if (xed - xst == 4)
                {
                    if (j == N || a[i][j + 1].color != a[i][j].color)
                    {
                        vector<Stone> v(a[i] + xst, a[i] + xed + 1);
                        sort(v.begin(), v.end(), cmp);
                        minSeq = min(v.back().seq, minSeq);
                    }
                }
            }
            else
            {
                xst = xed = j;
            }
        }
    }

    int yst, yed;
    for (int i = 1; i <= 20; i++)
    {
        yst = yed = 1;
        for (int j = 2; j <= 20; j++)
        {
            if (a[j][i].color > -1 && a[j][i].color == a[j - 1][i].color)
            {
                yed = j;
                if (yed - yst == 4)
                {
                    if (j == N || a[j + 1][i].color != a[j][i].color)
                    {
                        vector<Stone> v;
                        for (int k = yst; k <= yed; k ++)
                            v.push_back(a[k][i]);

                        sort(v.begin(), v.end(), cmp);
                        minSeq = min(v.back().seq, minSeq);
                    }
                }
            }
            else
            {
                yst = yed = j;
            }
        }
    }

    pair<int, int> cst, ced;
    for (int i = 2; i <= 20 - 4; i++)
    {
        for (int j = 2; j <= 20 - 4; j++)
        {
            cst.first = ced.first = i;
            cst.second = ced.second = j;
            for (int d = 0; d < 4; d++)
            {
                if (a[i + d][j + d].color > -1 && a[i + d][j + d].color == a[i + d - 1][j + d - 1].color)
                {
                    ced.first = i + d;
                    ced.second = j + d;
                    if (ced.first - cst.first == 4)
                    {
                        if (a[i + d + 1][j + d + 1].color != a[i + d][j + d].color)
                        {
                            vector<Stone> v;
                            for (int k = cst.first, p = cst.second; k <= ced.first && p <= ced.second; k++, p++)
                                v.push_back(a[k][p]);

                            sort(v.begin(), v.end(), cmp);
                            minSeq = min(v.back().seq, minSeq);
                        }
                    }
                }
                else
                    break;
            }
        }
    }

    pair<int, int> rcst, rced;
    for (int i = 2; i <= 20 - 4; i++)
    {
        for (int j = 2 + 4; j <= 20; j++)
        {
            rcst.first = rced.first = i;
            rcst.second = rced.second = j;
            for (int d = 0; d < 4; d++)
            {
                if (a[i + d][j - d].color > -1 && a[i + d][j - d].color == a[i + d - 1][j - d + 1].color)
                {
                    ced.first = i + d;
                    ced.second = j - d;
                    if (ced.first - cst.first == 4)
                    {
                        if (a[i + d + 1][j - d - 1].color != a[i + d][j - d].color)
                        {
                            vector<Stone> v;
                            for (int k = cst.first, p = cst.second; k <= ced.first && p >= ced.second; k++, p--)
                                v.push_back(a[k][p]);

                            sort(v.begin(), v.end(), cmp);
                            minSeq = min(v.back().seq, minSeq);
                        }
                    }
                }
                else
                    break;
            }
        }
    }

    cout << minSeq;
}