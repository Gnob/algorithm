#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string a, b, c, d, ab, cd;
    int limit, abLen, cdLen;
    unsigned long long degree = 1, x = 0, y = 0;

    cin >> a >> b >> c >> d;

    ab = a + b;
    cd = c + d;

    abLen = ab.size();
    cdLen = cd.size();

    if (abLen < cdLen)
        limit = cdLen;
    else
        limit = abLen;

    reverse(ab.begin(), ab.end());
    reverse(cd.begin(), cd.end());

    for (int i = 0; i < limit; ++i, degree *= 10) {
        if (i < abLen)
            x += (ab[i] - '0') * degree;
        if (i < cdLen)
            y += (cd[i] - '0') * degree;
    }

    cout << x + y;

    return 0;
}
