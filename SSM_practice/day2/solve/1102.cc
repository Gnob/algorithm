#include <cstdio>
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int a[16][16];
unsigned int d[1 << 16];
int P;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> a[i][j];

	char buf[17];
	scanf("%s", buf);
	cin >> P;

	int len = 0;
	for (int i = 0; buf[i]; i++) len++;

	int start = 0;
	for (int i = 0; i < len; i++)
		if (buf[i] == 'Y')
			start += 1 << i;

	const int bound = 1 << N;

	for (int i = 1; i < bound; i++)
		d[i] = numeric_limits<int>::max();	

	d[start] = 0;

	for (int i = 1; i < bound; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if ((i & (1 << j)) > 0 && (i & (1 << k)) == 0)
				{
					d[i | (1 << k)] = min(d[i | (1 << k)], d[i] + a[j][k]);
				}
			}
		}
	}

	unsigned int ans = numeric_limits<unsigned int>::max();

	for (int i = (1 << P) - 1; i < bound; i++)
	{
		int cnt = 0;
		for (int j = 0; j < N; j++)
			if ((i & (1 << j)) > 0) cnt++;
		if (cnt >= P)
			ans = min(ans, d[i]);
	}

	cout << ans;
}
