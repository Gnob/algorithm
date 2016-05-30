#include <iostream>

using namespace std;

int main() {
    int N, count = 0, target;
    bool isPrime = true;

    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        isPrime = true;
        scanf("%d", &target);
        if (target == 1) continue;

        for (int j = 2; j * j <= target; ++j) {
            if(target % j == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) count++;
    }

    printf("%d", count);


    return 0;
}