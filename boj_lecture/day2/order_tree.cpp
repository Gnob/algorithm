#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int N = 1;

vector<pair<int, int>> tree(26);

void preorder(int now) {
    printf("%c", now + 'A');

    if (tree[now].first != -1)
        preorder(tree[now].first);

    if (tree[now].second != -1)
        preorder(tree[now].second);
}

void inorder(int now) {
    if (tree[now].first != -1)
        inorder(tree[now].first);

    printf("%c", now + 'A');

    if (tree[now].second != -1)
        inorder(tree[now].second);
}

void postorder(int now) {
    if (tree[now].first != -1)
        postorder(tree[now].first);

    if (tree[now].second != -1)
        postorder(tree[now].second);

    printf("%c", now + 'A');
}

int main() {
    cin >> N;
    int TN = N, cur_idx, left_idx, right_idx;
    char tmp;

    while (TN--) {
        cin >> tmp;
        cur_idx = tmp - 'A';

        cin >> tmp;
        if (tmp == '.')
            left_idx = -1;
        else
            left_idx = tmp - 'A';

        cin >> tmp;
        if (tmp == '.')
            right_idx = -1;
        else
            right_idx = tmp - 'A';

        tree[cur_idx] = {left_idx, right_idx};
    }

    preorder(0);
    printf("\n");
    inorder(0);
    printf("\n");
    postorder(0);


    return 0;
}
