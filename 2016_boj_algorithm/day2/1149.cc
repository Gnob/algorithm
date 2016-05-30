#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int a[1001][3];
int d[1001][3];

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
	}

	for (int i = 1; i <= N; i++)
	{
		d[i][0] = a[i][0] + min(d[i - 1][1], d[i - 1][2]);
		d[i][1] = a[i][1] + min(d[i - 1][0], d[i - 1][2]);
		d[i][2] = a[i][2] + min(d[i - 1][0], d[i - 1][1]);
	}

	int result = min(d[N][0], min(d[N][1], d[N][2]));
	
	cout << result;
}
