#include <iostream>
#include <vector>

using namespace std;

int d[2001][2001];
int a[2001];

// 모든 경우를 구하고 싶으면 아래와 같이 짜야함 (모두 메모이제이션)
int godp(const int &st, const int &ed) {
    if (st == ed) {
        return d[st][ed] = 2;
    }

    if (st + 1 == ed) {
        if (a[st] == a[ed])
            return d[st][ed] = 2;
        else
            return d[st][ed] = 1;
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

    // 부분 만큼 호출 
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; ++j) {
            godp(i, j);
        }
    }

    int M;

    cin >> M;

    while(M--) {
        int st, ed;
        scanf("%d %d", &st, &ed);

        cout << d[st][ed] - 1 << "\n";
    }

}
