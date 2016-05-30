#include <iostream>
#include <vector>
#include <climits>

using namespace std;


long long d[401][401];

int main() {
    int V, E;
    
    scanf("%d %d", &V, &E);
    
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            d[i][j] = INT32_MAX;
        }
    }
    
    for (int i = 0; i < E; i++) {
        long long x, y, z;
        scanf("%lld %lld %lld", &x, &y, &z);
        d[x][y] = min(z, d[x][y]);
    }
    
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    
    long long min = INT32_MAX;
    
    for (int i = 1; i <= V; i++) {
        if (d[i][i] < min)
            min = d[i][i];
    }
    
    if (min == INT32_MAX)
        cout << -1;
    else
        cout << min;
}