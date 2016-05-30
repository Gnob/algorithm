#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int N, arg;
    char cmd[80] = "";

    unsigned int set = 0;

    cin >> N;

    while (N--) {
        scanf("%s", cmd);

        if (strcmp(cmd, "add") == 0) {
            scanf("%d", &arg);

            set |= (1 << arg);
        }
        else if (strcmp(cmd, "remove") == 0) {
            scanf("%d", &arg);

            set = set & ~(1 << arg);
        }
        else if (strcmp(cmd, "check") == 0) {
            scanf("%d", &arg);

            if (set & (1 << arg)) cout << 1;
            else cout << 0;
            printf("\n");
        }
        else if (strcmp(cmd, "toggle") == 0) {
            scanf("%d", &arg);

            set ^= (1 << arg);
        }
        else if (strcmp(cmd, "all") == 0) {
            set = (1 << 21) - 1;
        }
        else if (strcmp(cmd, "empty") == 0) {
            set = 0;
        }
    }

    return 0;
}