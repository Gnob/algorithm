#include <iostream>

using namespace std;

int main() {
    string line;

    getline(cin, line);

    for (int i = 0; i < line.size(); ++i) {
        if ('A' <= line[i] && line[i] <= 'Z')
            line[i] = (line[i] - 'A' + 13) % 26 + 'A';
        else if ('a' <= line[i] && line[i] <= 'z')
            line[i] = (line[i] - 'a' + 13) % 26 + 'a';
    }

    cout << line;

    return 0;
}
