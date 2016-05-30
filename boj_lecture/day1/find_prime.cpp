#include <iostream>

using namespace std;

bool isDropped[1000001] = { true, true, false, };

int main() {
    int a, b;

    scanf("%d %d", &a, &b);

    for (int i = 2; i <= b; ++i) {
        for (int j = i * 2; j <= b; j += i) {
            if (!isDropped[j]) isDropped[j] = true;
        }
    }

    for (int k = a; k <= b; ++k) {
        if(!isDropped[k])
            printf("%d\n", k);
    }


    return 0;
}