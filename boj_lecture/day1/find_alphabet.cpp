#include <iostream>

using namespace std;

int main() {
    int pos[26], len, idx;
    string line;

    for (int k = 0; k < 26; ++k) {
        pos[k] = -1;
    }

    getline(cin, line);

    len = line.size();

    for (int i = 0; i < len; ++i) {
        idx = line[i] - 'a';
        if (pos[idx] == -1)
            pos[idx] = i;
    }

    for (int j = 0; j < 26; ++j) {
        cout << pos[j] << " ";
    }

    return 0;
}
