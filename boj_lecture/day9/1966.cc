#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N, M;
        scanf("%d %d", &N, &M);
        
        vector<int> v;
        queue<pair<int, int>> q;
        
        int tmp;
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &tmp);
            q.push(make_pair(tmp, i));
            v.push_back(tmp);
        }
        
        sort(v.begin(), v.end());
        
        for (int j = 0; j < N; j++)
        {
            auto top = q.front(); q.pop();
            
            if (v.back() == top.first)
            {
                v.pop_back();
                if (top.second == M)
                {
                    printf("%d", j);
                    break;
                }
            }
            else
            {
                q.push(top);
            }
        }
    }
}