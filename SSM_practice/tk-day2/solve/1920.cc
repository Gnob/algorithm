#include <iostream>
#include <algorithm>

using namespace std;

int a[100000];
int m[100000];

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);

	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
		scanf("%d", &m[i]);

	sort(a, a + N);

	for (int i = 0; i < M; i++)
		if (binary_search(a, a + N, m[i]))
			printf("1\n");
		else
			printf("0\n");
}
