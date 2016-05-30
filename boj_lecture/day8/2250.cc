#include <iostream>
#include <vector>
#include <list>

using namespace std;

int children[10001][2];
int parent[10001];
int width[10001][2];
int cnt;
int maxDepth;

void inorder(int node, int depth)
{
    if (children[node][0] > 0)
    {
        inorder(children[node][0], depth + 1);
    }

    maxDepth = max(depth, maxDepth);
    cnt++;
    if (width[depth][0] == 0 || width[depth][0] > cnt)
    {
        width[depth][0] = cnt;
    }
    if (width[depth][1] == 0 || width[depth][1] < cnt)
    {
        width[depth][1] = cnt;
    }

    if (children[node][1] > 0)
    {
        inorder(children[node][1], depth + 1);
    }

}

int main()
{
    int N; cin >> N;
    int node, l, r;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d", &node, &l, &r);
        children[node][0] = l;
        children[node][1] = r;
        if (l > 0)
            parent[l] = node;
        if (r > 0)
            parent[r] = node;
    }

    int root;
    for (int i = 1; i <= N; i++)
    {
        if (parent[i] == 0)
        {
            root = i;
            break;
        }
    }

    inorder(root, 1);

    int depth = 0;
    int maxWidth = 0;
    for (int i = 1; i <= maxDepth; i++)
    {
        if (maxWidth < width[i][1] - width[i][0] + 1)
        {
            depth= i;
            maxWidth = width[i][1] - width[i][0] + 1;
        }
    }

    cout << depth << " " << maxWidth;
}