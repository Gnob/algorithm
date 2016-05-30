#include<iostream>
#include<random>
using namespace std;

int main() {
    int i;
    int min = 1;
    int max = 100000;
    mt19937_64 rng(3244);
    uniform_int_distribution<__int64_t> dist(min, max);

    FILE *f = fopen("~/Lab/Algorithm/boj_lecture/in.txt", "w+");

    for (int j = 1; j <= 100000; ++j) {
        fprintf(f, "%d ", dist(rng));
    }

    fclose(f);
    return 0;
}