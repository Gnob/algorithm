#include<iostream>
#include<vector>
using namespace std;

int main() {
    int goal;
    int M, tmp;

    cin >> goal >> M;

    vector<int> v({0,1,2,3,4,5,6,7,8,9});
    vector<int> digit;

    for (int i = 0; i < M; ++i) {
        scanf("%d", &tmp);
        v[tmp] = -1;
    }

    for (vector<int>::iterator vi = v.begin(); vi != v.end(); vi++) {
        if (*vi == -1) {
            v.erase(vi--);
        }
    }

    tmp = goal;
    for (int j = 0; j < 6; ++j) {
        if (tmp != 0) {
            digit.push_back(tmp % 10);
            tmp /= 10;
        }
        else break;
    }

    int count = 0;
    bool isIncluded = false;
    while (!isIncluded) {
        count++;
        goal--;
        tmp = goal;

        for (int j = 0; j < 6; ++j) {
            isIncluded = false;

            if (tmp != 0) {
                int t = tmp % 10;

                for (int i = 0; i < v.size(); ++i) {
                    if (v[i] == t) {
                        isIncluded = true;
                        break;
                    }
                }
                if (!isIncluded) break;
                tmp /= 10;
            }
            else {
                isIncluded = true;
                break;
            }
        }
    }

    cout << digit.size() + count;

    return 0;
}