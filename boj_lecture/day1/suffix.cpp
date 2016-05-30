#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string S;

    cin >> S;

    vector<string> sVector;

    for (int i = 0; i < S.size(); ++i) {
        sVector.push_back(S.substr(i, S.size() - i));
    }

    sort(sVector.begin(), sVector.end());
    for (int i = 0; i < sVector.size(); ++i) {
        printf("%s\n", sVector.at(i).c_str());
    }

    return 0;
}
