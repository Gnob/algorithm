#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int l, c;
string cstr = "";

bool check(const string &pw) {
    int a = 0, b = 0;

    for (int i = 0; i < pw.size(); ++i) {
        if (pw[i] == 'a' || pw[i] == 'o' || pw[i] == 'i' || pw[i] == 'u' || pw[i] == 'e') {
            a++;
        }
        else b++;
    }

    return 1 <= a && 2 <= b;
}

void recur(const string &pw, const int idx) {
    if (pw.length() == l) {
        if (check(pw)) {
            cout << pw;
            printf("\n");
        }
        return;
    }
    if (idx >= c) return;

    recur(pw + cstr[idx], idx + 1);
    recur(pw, idx + 1);
}

int main() {
    char tmp;
    cin >> l >> c;
    for (int i = 0; i < c; ++i) {
        cin >> tmp;
        cstr += tmp;
    }
    sort(cstr.begin(), cstr.end());
    recur("", 0);

    return 0;
}