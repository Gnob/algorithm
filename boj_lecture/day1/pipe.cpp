#include <iostream>
#include <cstring>

using namespace std;

typedef int DATA;

DATA stack[100000];
unsigned int head = 0;

unsigned int size() {
    return head;
}

bool isEmpty() {
    return head == 0;
}

DATA peak() {
    return stack[head - 1];
}

void push(char ch) {
    stack[head++] = ch;
}

DATA pop() {
    if (isEmpty()) {
        return -1;
    }
    else {
        return stack[--head];
    }
}

int main() {
    int N, term;
    unsigned int count = 0;
    char buf[100001];

    scanf("%s", buf);

    N = strlen(buf);

    for (int i = 0; i < N; ++i) {
        if (buf[i] == '(') {
            push(i);
        }
        else {
            term = i - peak();
            pop();
            if (term == 1) {
                count += size();
            }
            else {
                count++;
            }
        }
    }

    printf("%d", count);

    return 0;
}