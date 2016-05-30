#include <iostream>

using namespace std;

int main() {
    int mod, number, radix, idx = 0;
    char buf[10000000];

    scanf("%d %d", &number, &radix);

    while (number > 0) {
        mod = number % radix;
        number /= radix;

        if (mod < 10)
            buf[idx++] = '0' + mod;
        else
            buf[idx++] = 'A' + mod - 10;
    }

    for (int i = idx - 1; i >= 0; --i) {
        printf("%c", buf[i]);
    }

    return 0;
}