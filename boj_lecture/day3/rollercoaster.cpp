#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Walker {
    int r;
    int c;
};

vector<vector<int>> v;

void printMap(const Walker &a, const Walker &b, const Walker &m, const int mode) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            if (mode == 0 && i == m.r && j == m.c) printf("X ");
            else if (mode == 0 && i == a.r && j == a.c) printf("A ");
            else if (mode == 0 && i == b.r && j == b.c) printf("B ");
            else printf("%d ", v[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int R, C, min = 1001, mr, mc;
    cin >> R >> C;

    for (int i = 0; i < R; ++i) {
        v.emplace_back();
        for (int j = 0; j < C; ++j) {
            int tmp;
            scanf("%d", &tmp);

            if ((i + j) % 2 == 1 && tmp < min){
                min = tmp;
                mr = i;
                mc = j;
            }

            v[i].push_back(tmp);
        }
    }

    if (C % 2 == 1) {
        for (int j = 0; j < R; ++j) {
            char dir = (j % 2 == 0) ? 'R' : 'L';
            for (int i = 0; i < C - 1; ++i) {
                printf("%c", dir);
            }
            if (j < R - 1)
                printf("D");
        }
    }
    else if (R % 2 == 1) {
        for (int j = 0; j < C; ++j) {
            char dir = (j % 2 == 0) ? 'D' : 'U';
            for (int i = 0; i < R - 1; ++i) {
                printf("%c", dir);
            }
            if (j < C - 1)
                printf("R");
        }
    }
    else {
        Walker a{0, 0}, b{R - 1, C - 1};
        const Walker m{mr, mc};
        string upper = "", lower = "";

        while (a.r + 1 < m.r) {
            a.r += 2;
        }

        for (int j = 0; j < a.r; ++j) {
            char dir = (j % 2 == 0) ? 'R' : 'L';
            for (int i = 0; i < C - 1; ++i) {
                upper.push_back(dir);
            }
            upper.push_back('D');
        }

        while (a.c + 1 < m.c) {
            a.c += 2;
        }

        for (int j = 0; j < a.c; ++j) {
            char dir = (j % 2 == 0) ? 'D' : 'U';
            upper.push_back(dir);
            upper.push_back('R');
        }

        if (a.c + 1 == m.c) {
            upper.push_back('D');
            upper.push_back('R');
        }
        else {
            upper.push_back('R');
            upper.push_back('D');
        }

//        cout << upper << endl;


        while (m.c < b.c - 1) {
            b.c -= 2;
        }

        for (int j = b.c + 1; j < C; ++j) {
            char dir = (j % 2 == 0) ? 'U' : 'D';
            lower.push_back('R');
            lower.push_back(dir);
        }

        while (m.r < b.r - 1) {
            b.r -= 2;
        }

        for (int j = b.r + 1; j < R; ++j) {
            char dir = (j % 2 == 0) ? 'L' : 'R';
            lower.push_back('D');
            for (int i = 0; i < C - 1; ++i) {
                lower.push_back(dir);
            }
        }

//        cout << lower << endl;

//        printMap(a, b, m, 0);

        cout << upper << lower;
    }




    return 0;
}
