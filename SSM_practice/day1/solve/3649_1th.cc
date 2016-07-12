#include <cstdio>

using namespace std;

char is_exist[100000001];
int b[1000001];

int main()
{
	int x, n;

	while (scanf("%d", &x) == 1)
	{
		scanf("%d", &n);

		x *= 10000000;

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &b[i]);
			is_exist[b[i]]++;
		}

		/*
		   printf("%d\n%d\n", x, n);

		   for (int i = 0; i < n; i++)
		   printf("%d\n", b[i]);
		   */

		int start = x <= 100000000 ? x - 1 : 100000000;
		int end = x / 2 + (x % 2 ? 1 : 0);

		int remain = -1;

		for (int i = start; i >= end; i--)
		{
			if (is_exist[i])
			{
				is_exist[i]--;
				remain = x - i;
				if (is_exist[remain])
					break;
				else
					remain = -1;
			}
		}

		if (remain == -1)
			printf("danger\n");
		else
			printf("yes %d %d\n", remain, x - remain);

		for (int i = 0; i < n; i++)
			is_exist[b[i]] = 0;
	}
}
