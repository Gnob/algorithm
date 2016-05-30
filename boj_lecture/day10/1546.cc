#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    const long long C = 1000000;
    const double dC = 1000000;
    int N; cin >> N;
    long long sum = 0;

    vector<long long> v(N);

    for (int i = 0; i < N; i++)
    {
        long long tmp;
        scanf("%lld", &tmp);
        v[i] = tmp * C;
    }

    sort(v.begin(), v.end());

    long long divider = v.back() / C;
    for (int i = 0; i < N; i++)
    {
        v[i] /= divider;
        v[i] *= 100;
    }

    for (long long e: v)
    {
        sum += e;
    }
    double dN = N;

    printf("%.2f", (sum / N) / dC);
}