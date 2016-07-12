#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

int memo[100001];

int main()
{
	int N;

	cin >> N;

	memo[0] = 0;
	memo[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		int x = sqrt(i);

		if (i == x * x)
			memo[i] = 1;
		else
		{
			memo[i] = numeric_limits<int>::max();
			for (int j = x; j > 0; j--)
				memo[i] = min(memo[i], memo[j * j] + memo[i - j * j]);
		}
	}
	
	cout << memo[N];
}

