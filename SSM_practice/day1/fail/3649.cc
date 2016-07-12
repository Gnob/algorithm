#include <cstdio>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

set<int> is_exist;
unordered_map<int, int> counter;
int b[1000001];

bool cmp(const int &lhs, const int &rhs)
{
	return lhs < rhs;
}

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
			is_exist.insert(b[i]);
			counter[b[i]]++;
		}

		sort(b, b + n);

		int remain = -1;

		for (int i = 0; i < n; i++)
		{
			if (is_exist.count(b[i]))
			{
				remain = x - b[i];

				if (remain == b[i] && counter[b[i]] == 1)
					continue;
					
				if (is_exist.count(remain))
					break;
				else
					remain = -1;
			}
		}

		int ans = x - remain;

		if (remain > ans)
			swap(remain, ans);

		if (remain == -1)
			printf("danger\n");
		else
			printf("yes %d %d\n", remain, ans);

		is_exist.clear();
		counter.clear();
	}
}
