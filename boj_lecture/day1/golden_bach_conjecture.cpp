#include <iostream>

using namespace std;

bool isDropped[1000001] = { true, true, false, };
int primeArr[1000001] = { 0, };

int main() {
    int N = 1, idx = 0, other;

    for (int i = 2; i <= 1000000; ++i) {
        for (int j = i * 2; j <= 1000000; j += i) {
            if (!isDropped[j]) isDropped[j] = true;
        }
    }

    for (int k = 0; k <= 1000000; ++k) {
        if (!isDropped[k])
            primeArr[idx++] = k;
    }

    while (N > 0) {
        scanf("%d", &N);

        for (int i = 0; primeArr[i] < N; ++i) {
            other = N - primeArr[i];
            if(!isDropped[other]) {
                printf("%d = %d + %d\n", N, primeArr[i], other);
                break;
            }
        }
    }


    return 0;
}
