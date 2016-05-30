#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int cnt = 0;
	int lvl = 1;

	struct {
		int left;
		int right;
	} ans;

	ans.left = 0;
	ans.right = 1;

	while (cnt < N)
	{
		for (int i = 0; i < lvl && cnt < N; i++, cnt++)
		{
			if (lvl % 2 == 1)
			{
				if (i == 0)
				{
					ans.left += 1;
				}
				else
				{
					ans.left -= 1;
					ans.right += 1;
				}
			} 
			else
			{
				if (i == 0)
				{
					ans.right += 1;
				}
				else
				{
					ans.left += 1;
					ans.right -= 1;
				}
			}
		}
		lvl++;
	}

	cout << ans.left << '/' << ans.right;
}
