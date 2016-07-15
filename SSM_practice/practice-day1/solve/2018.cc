/*
[bdoc #two-pointer]
[/bdoc]
 */
#include <iostream>

using namespace std;

int main()
{
	int N; cin >> N;

	int left, right;
	left = right = 1;

	int sum = 1;
	int cnt = 1;
	while (right < N &&left <= right)
	{
		if (sum < N)
		{
			right++;
			sum += right;
		}
		else if (N < sum)
		{
			sum -= left;
			left++;
		}
		else if (right - left >= 1)
		{
			cnt++;
			right++;
			sum += right;
		}
		else
			break;
	}

	cout << cnt;
}
