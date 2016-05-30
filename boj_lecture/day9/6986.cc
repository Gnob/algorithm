#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    const long long C = 10000000;
    int N, K;
    cin >> N >> K;

    char buf[80];
    vector<long long> v;

    for (int i = 0; i < N; i++)
    {
        scanf("%s", buf);
        if (buf[0] == '1' && buf[1] == '0')
        {
            v.push_back(10 * 10 * C);
        }
        if (buf[1] == '.')
        {
            long long f = buf[0] - '0', s = buf[2] - '0';
            v.push_back(f * 10 * C + s * C);
        }
    }

    sort(v.begin(), v.end());

    long long sum = 0, aavg = 0;
    for (int i = K; i < N - K; i++)
    {
        sum += v[i];
    }

    aavg = sum / (N - 2 * K);
    long long r = (aavg / 100000) % 10;

    if (r >= 5)
        aavg += C / 10;


    sum = 0;
    long long cavg = 0;
    for (int i = 0; i < K; i++)
    {
        sum += v[K];
    }
    for (int i = K; i < N - K; i++)
    {
        sum += v[i];
    }
    for (int i = N - K; i < N; i++)
    {
        sum += v[N - K - 1];
    }

    cavg = sum / N;
    r = (cavg / 100000) % 10;

    if (r >= 5)
        cavg += C / 10;

    printf("%.2f\n", (aavg / (C / 10)) / 100.0F);
    printf("%.2f", (cavg / (C / 10)) / 100.0F);
}