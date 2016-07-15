#include <cstdio>
#include <iostream>
#include <algorithm>

#define x first
#define y second
#define what first
#define is_c second
#define ch first
#define gu first

using namespace std;

typedef pair<int, int> pii;
typedef pair<pair<int, int>, int> ppi;

ppi mx[100001]; // 전체 광물
ppi my[100001]; // 전체 광물

int main(int argc, char** argv) {
	setbuf(stdout, NULL);

	int T;
	int test_case;
    
	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		int N;
		scanf("%d", &N);
       
		int total_ch = 0;
		int total_gu = 0;
		for (int i = 1; i <= N; i++)
		{
			scanf("%d %d %d", &mx[i].what.x, &mx[i].what.y, &mx[i].is_c);
			my[i].what.y = mx[i].what.x;
			my[i].what.x = mx[i].what.y;
			my[i].is_c = mx[i].is_c;

			if (my[i].is_c)
				total_ch++;
			else
				total_gu++;
		}

		sort(mx + 1, mx + N + 1);
		sort(my + 1, my + N + 1);
		
		int max_ans = 0;
		int ans = total_gu;
		int backup = ans;

		for (int i = 0; i <= N; i++)
		{
			if (i >= 1)
			{
				ans = backup;
				if (my[i].is_c)
					ans++;
				else
					ans--;
				backup = ans;
			}

			for (int j = 1; j <= N; j++)
			{
				max_ans = max(ans, max_ans);

				if (mx[j].is_c)
				{
					if (mx[j].what.y <= i)
						ans--;
					else
						ans++;
				}
				else
				{
					if (mx[j].what.y <= i)
						ans++;
					else
						ans--;
				}
			}

			max_ans = max(ans, max_ans);
		}

		printf("Case #%d\n", test_case);
		printf("%d\n", max_ans);
	}

	return 0;
}

