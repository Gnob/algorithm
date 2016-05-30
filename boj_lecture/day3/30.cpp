#include <iostream>
#include <functional>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string buf = "";
    cin >> buf;

    sort(buf.begin(), buf.end(), greater<int>());

    if (buf[buf.length() - 1] != '0') cout << "-1\n";
    else {
        unsigned int sum = 0;
        for (int i = 0; i < buf.length(); ++i) {
            sum += buf[i] - '0';
        }

        if((sum % 3) == 0) {
            cout << buf;
        }
        else cout << -1;
    }

    return 0;
}