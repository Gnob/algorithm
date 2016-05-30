#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	vector<int> v, d;
	v.push_back(-1);
	d.push_back(-1);

	for (int i = 1; i <= N; i++)
	{
		v.push_back(0);
		scanf("%d", &v[i]);
		d.push_back(v[i]);
	}

	bool is_ans = true;

	for (int i = 1; i <= N; i++)
	{
		if (d[i] == i)
		{
			is_ans = false;
			break;
		}
		printf("%d ", d[i]);
	}
			printf("\n");

	long long n;

	if (is_ans)
	{
		for (n = 1; n < 20000000; n++)
		{
			int cnt = 0;
			is_ans = true;

			for (int i = 1; i <= N; i++)
			{
				d[i] = v[d[i]];
				printf("%d ", d[i]);

				if (d[i] == v[i]) cnt++;
				if (i == d[i])
					is_ans = false;
			}

			printf("\n");

			if (cnt == N) 
				break;

			if (is_ans)
				break;
		}
	}
	
	if (n == 20000000)
		printf("-1");
	else if (is_ans)
		printf("%lld", n + 1);
	else
		printf("-1");
}
