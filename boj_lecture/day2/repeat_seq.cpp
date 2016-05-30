#include<iostream>

using namespace std;

int A, P;

int arr[300000];
bool check[300000];
int cnt;

int nextIdx(int curValue) {
    int digitCnt, sum = 0, subsum = 1;
    int digit[10];

    digitCnt = 0;

    for (int i = 0; i < 10; ++i) {
        digitCnt++;
        digit[i] = curValue % 10;
        curValue /= 10;
        if (curValue == 0) break;
    }

    for (int d = 0; d < digitCnt; d++) {
        subsum = 1;
        for (int i = 0; i < P; ++i) {
            subsum *= digit[d];
        }
        sum += subsum;
    }

    return sum;
}

int DFS(int v) {
    int nextV = nextIdx(v);
    arr[v] = cnt++;
    check[v] = true;

    if (!check[nextV]) {
        return DFS(nextV);
    }
    else {
        return arr[nextV];
    }
}

int main() {

    cin >> A >> P;

    cout << DFS(A);

    return 0;
}
