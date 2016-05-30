#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const string &a, const string &b)
{
    return make_pair(a.size(), a) < make_pair(b.size(), b);
}

int main()
{
    int N; cin >> N;
    vector<string> v(N);
    
    while (N--)
        cin >> v[N];   
    
    sort(v.begin(), v.end(), cmp);
    
    v.erase(unique(v.begin(), v.end()), v.end());
    
    for (auto k : v) {
        cout << k;
        printf("\n");
    }
}