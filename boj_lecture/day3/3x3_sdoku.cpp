#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v;

int main() {
    int tmp;

    for (int i = 0; i < 9; ++i) {
        v.emplace_back();
        for (int j = 0; j < 9; ++j) {
            scanf("%d", &tmp);
            v.back().push_back(tmp);
        }
    }



    return 0;
}