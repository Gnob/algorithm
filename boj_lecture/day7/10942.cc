#include <iostream>
#include <vector>

using namespace std;

int d[2001][2001];
int a[2001];

int godp(const int &st, const int &ed) {
    if (st == ed) {
        return 2;
    }

    if (st + 1 == ed) {
        if (a[st] == a[ed])
            return 2;
        else
            return 1;
    }

    if (a[st] == a[ed]) {
        return d[st][ed] = godp(st + 1, ed - 1);
    }
    else {
        return d[st][ed] = 1;
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
    }

    int M;

    cin >> M;

    while(M--) {
        int st, ed;
        scanf("%d %d", &st, &ed);

        cout << (godp(st, ed) - 1) << "\n";
    }

}
