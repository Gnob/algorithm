#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[9];
vector<int> v;

bool gorc(int idx, int sum, int cnt)
{
    if (sum > 100)
        return false;
    if (cnt > 7)
        return false;

    if (sum == 100 && cnt == 7) {
        v.push_back(a[idx]);
        return true;
    }

    for (int i = idx + 1; i < 9; i++)
    {
        if (gorc(i, sum + a[i], cnt + 1))
        {
            v.push_back(a[idx]);
            return true;
        }
    }

    return false;
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &a[i]);
    }

    sort(a, a + 9);

    gorc(0, a[0], 1);

    reverse(v.begin(), v.end());
    for (int e: v)
    {
        cout << e << "\n";
    }
}