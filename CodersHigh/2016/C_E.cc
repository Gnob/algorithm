#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	vector<int> v;
	v.push_back(-1);

	for (int i = 1; i <= N; i++)
	{
		v.push_back(0);
		scanf("%d", &v[i]);
	}

	bool is_ans = true;

	for (int i = 1; i <= N; i++)
	{
		if (v[i] == i)
		{
			is_ans = false;
			break;
		}
	}
	
	if (is_ans)
		printf("%d", N + 1);
	else
		printf("-1");
}
