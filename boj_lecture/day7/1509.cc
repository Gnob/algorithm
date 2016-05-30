#include <iostream>
#include <cstdio>

using namespace std;

int dd[2501];
int d[2501][2501];
string str;

int main() {
    cin >> str;

    int N = str.length();


    for (int i = 1; i <= N; i++) {
        d[i][i] = 2;
    }

    for (int i = 1; i <= N - 1; i++) {
        if (str[i] == str[i-1])
            d[i][i+1] = 2;
        else
            d[i][i+1] = 1;
    }

    // 기준점을 잡고 일정 길이만큼 먼저 이동한다
    for (int k = 2; k <= N - 1; k++) {
        for (int i = 1; i <= N - k; i++) {
            int j = k + i;
            if (str[i-1] == str[j-1] && d[i + 1][j - 1] == 2)
                d[i][j] = 2;
            else
                d[i][j] = 1;
        }
    }

    for (int i = 1; i <= N; i++) {
        dd[i] = 2000000000;
        for (int j = 1; j <= i ; j++) {
            if (d[j][i] == 2)
                dd[i] = min(dd[i], dd[j-1] + 1);
        }
    }

    cout << dd[str.length()];
}