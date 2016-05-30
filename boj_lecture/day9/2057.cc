#include <iostream>
#include <vector>

using namespace std;

vector<unsigned long long> v;

unsigned long long N;
unsigned long long d[21];

unsigned long long fact(unsigned long long n)
{
    if (n == 1)
        return d[n] = 1;

    if (d[n])
        return d[n];

    return d[n] = n * fact(n - 1);
}

bool gorc(int idx, unsigned long long sum)
{
    if (idx > 20)
        return false;
    if (sum > N)
        return false;

    if (sum == N)
        return true;

    for (int i = idx + 1; i < 20; ++i) {
        if (gorc(i, sum + d[i])) {
            v.push_back(d[i]);
            return true;
        }
    }

    return false;
}

int main()
{
    fact(20);

    cin >> N;

    unsigned long long sum = 0;

    d[0] = 1;

    if (N == 0) cout << "NO";
    else cout << (gorc(-1, 0) ? "YES" : "NO");

//    printf("\n");
//
//    for (int i = 1; i < 20; ++i) {
//        cout << d[i] << " ";
//    }
//    printf("\n");
//    for (auto k : v) {
//        cout << k; printf("\n");
//    }
}