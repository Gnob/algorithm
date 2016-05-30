#include <iostream>

using namespace std;

int main() {
    int digit, number = 0, radix;
    char buf[10000000];

    scanf("%s %d", buf, &radix);

    for (int i = 0; buf[i]; ++i) {
        if (buf[i] <= '9') {
            digit = buf[i] - '0';
        }
        else {
            digit = buf[i] - 'A' + 10;
        }
        number *= radix;
        number += digit;
    }

    printf("%d", number);

    return 0;
}