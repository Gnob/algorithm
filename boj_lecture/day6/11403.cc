#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int d[101][101];


int main() {
    int V;
    scanf("%d", &V);

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            scanf("%d", &d[i][j]);
        }
    }

    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (d[i][k] == 1 && d[k][j] == 1)
                    d[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }

}