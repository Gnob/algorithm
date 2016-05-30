#include<iostream>
#include<cstdio>

using namespace std;

int d[2][3];

int main()
{
	int N = 1;
	int T = 0;

	while (scanf("%d", &N), N != 0)
	{
		T++;

		int pre = 0, now = 1; 

		scanf("%d %d %d", &d[pre][0], &d[pre][1], &d[pre][2]);
		d[pre][2] += d[pre][1];

		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		d[now][0] = a + d[pre][1];
		d[now][1] = b + min(min(d[now][0], d[pre][1]), d[pre][2]);
		d[now][2] = c + min(min(d[now][1], d[pre][1]), d[pre][2]);

		for (int i = 2; i < N; i++)
		{
			now = i % 2;
			pre = (i + 1) % 2;

			scanf("%d %d %d", &a, &b, &c);

			d[now][0] = a + min(d[pre][0], d[pre][1]) ;
			d[now][1] = b + min(min(d[now][0], d[pre][1]), min(d[pre][2], d[pre][0]));
			d[now][2] = c + min(min(d[now][1], d[pre][1]), d[pre][2]);
		}

		printf("%d. %d\n", T, d[now][1]);
	}
}
