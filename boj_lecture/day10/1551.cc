#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> v(N);

    for (int i = 0; i < N - 1; i++)
    {
        scanf("%d,", &v[i]);
    }
    scanf("%d", &v[N - 1]);

    for (int j = 1; j <= K; j++)
    {
        for (int i = N - 1; i >= j; i--)
        {
            v[i] -= v[i - 1];
        }
    }

    vector<int> vv(v.begin() + K , v.end());

    for (int i = 0; i < vv.size() - 1; i++)
    {
        printf("%d,", vv[i]);
    }

    printf("%d", vv.back());
}