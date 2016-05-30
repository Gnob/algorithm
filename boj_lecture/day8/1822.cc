#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    int N, M;

    cin >> N >> M;

    unordered_map<int, bool> hash;
    vector<int> v(N), w(M);
    vector<bool> isDel(N);

    isDel.assign(N, false);

    while (N--)
    {
        scanf("%d", &v[N]);
    }

    sort(v.begin(), v.end());

    while (M--)
    {
        int tmp;
        scanf("%d", &tmp);

        hash.emplace(tmp, true);
    }

    int cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (hash.find(v[i]) != hash.end())
        {
            isDel[i] = true;
            cnt++;
        }
    }

    printf("%d\n", v.size() - cnt);
    for(int i = 0; i < v.size(); i++)
    {
        if (isDel[i] == false)
        {
            printf("%d ", v[i]);
        }
    }
}