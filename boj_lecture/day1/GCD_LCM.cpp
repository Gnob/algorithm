#include <iostream>

using namespace std;

int GCD(int x, int y) {
    if (y == 0) {
        return x;
    }
    else {
        return GCD(y, x % y);
    }
}

int LCM(int x, int y, int gcd) {
    return (x / gcd) * (y / gcd) * gcd;
}

int main() {
    int gcd, a, b;

    scanf("%d %d", &a, &b);

    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }
    gcd = GCD(a, b);
    printf("%d\n%d", gcd, LCM(a, b, gcd));
    return 0;
}