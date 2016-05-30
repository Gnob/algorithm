#include <iostream>
#include <vector>

using namespace std;

vector<unsigned int> heap(131073);
int idx;

unsigned int pop() {
    unsigned int min = heap[1];

    heap[1] = heap[idx--];

    int now = 1;

    while (now < idx) {
        int child = now * 2;
        if (child > idx)
            break;
        else if (child != idx && heap[child] > heap[child + 1])
            child++;

        if (heap[now] > heap[child]) {
            swap(heap[now], heap[child]);
            now = child;
        }
        else
            break;
    }

    return min;
}

void push(const unsigned int x) {
    heap[++idx] = x;
    int now = idx;
    while (now != 1 && heap[now/2] > heap[now]) {
        swap(heap[now/2], heap[now]);
        now /= 2;
    }
}

bool isEmpty() {
    return idx == 0;
}

int main() {
    int N;
    cin >> N;

    while (N--) {
        unsigned int x;
        scanf("%d", &x);

        if(x != 0) {
            push(x);
        }
        else {
            if (isEmpty()) printf("0\n");
            else printf("%u\n", pop());
        }
    }


    return 0;
}