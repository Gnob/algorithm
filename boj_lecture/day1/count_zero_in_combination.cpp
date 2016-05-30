#include <iostream>

using namespace std;

int main() {
    unsigned long long int five_divider = 5, two_divider = 2, five_count = 0, two_count = 0;
    unsigned long long int M, N, T;

    cin >> M >> N;

    T = M - N;

    while (M / five_divider) {
        five_count += M / five_divider - N / five_divider - T / five_divider;
        five_divider *= 5;
    }

    while (M / two_divider) {
        two_count += M / two_divider - N / two_divider - T / two_divider;
        two_divider *= 2;
    }

    printf("%llu", min(five_count, two_count));

    return 0;
}
