#include <iostream>

using namespace std;

int main() {
    int lower_case = 0, upper_case = 0, number = 0, space = 0;
    string line = "init";

    while (getline(cin, line)) {
        lower_case = 0, upper_case = 0, number = 0, space = 0;
        for (int i = 0; i < line.size(); ++i) {
            if ('A' <= line[i] && line[i] <= 'Z')
                upper_case++;
            else if ('a' <= line[i] && line[i] <= 'z')
                lower_case++;
            else if ('0' <= line[i] && line[i] <= '9')
                number++;
            else if (line[i] == ' ')
                space++;
        }

        printf("%d %d %d %d\n", lower_case, upper_case, number, space);
    }

    return 0;
}
