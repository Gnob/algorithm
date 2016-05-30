#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;
    vector<int> v;
    for (int i = 1; i * i <= N; i++)
    {
        if (M <= i * i)
            v.push_back(i * i);
    }
    
    for (auto k : v) {
        cout << k;
        printf("\n");
    }
}