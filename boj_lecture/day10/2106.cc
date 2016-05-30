#include <iostream>
#include <climits>

string map[50][5];

int main()
{
    int N; cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> map[i][j];
        }
    }
    
    int ans = INT32_MAX;
    int p, q;
    
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; < N; j++)
        {
            int cnt = 0;
            for (int x = 0; x < 5; x++)
            {
                for (int y = 0; y < 7; y++)
                {
                    if (map[i][x][y] != map[j][x][y])
                        cnt++;
                }
            }
            
            if (cnt < ans)
            {
                ans = cnt;
                p = i;
                q = j;
            }
        }
    }
    
    cout << p << " " << q;
}