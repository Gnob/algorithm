#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    stack<int> p_stack;
    string buf;
    int N, term;
    unsigned int count = 0;

    cin >> buf;

    N = buf.length();

    for (int i = 0; i < N; ++i) {
        if (buf[i] == '(') {
            p_stack.push(i);
        }
        else {
            term = i - p_stack.top();
            p_stack.pop();
            if (term == 1) {
                count += p_stack.size();
            }
            else {
                count++;
            }
        }
    }

    printf("%d", count);

    return 0;
}