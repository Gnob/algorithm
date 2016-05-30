#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

char m[50][50];
int a[50][50];
int d[50][50];
int c[50][50];

int N;
int k, nowChk;
pair<int,int> s;
vector< pair<int,int> > v;
int dir[8][2] = {
	{ 1, 0 }, { 1, 1 }, { 0, 1 }, { -1, 1 },  
	{ -1, 0 }, { -1, -1 }, { 0, -1 }, { 1, -1 }   
};

struct {
	int min;
	int max;
} status;

bool godp(const int &x, const int &y)
{
	if (k == v.size())
		return true;

	c[x][y] = nowChk;
	for (int i = 0; i < 8; i++)
	{
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (0 <= nx && nx < N && 0 <= ny && ny < N && c[nx][ny] != nowChk) 
		{
			if (status.min <= a[nx][ny] && a[nx][ny] <= status.max)
			{
				if (m[nx][ny] == 'K') k++; 
				if (godp(nx, ny))
					return true;
			}
		}
	}

	return false;
}


int main ()
{
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		scanf("%s", m[i]);
		for (int j = 0; j < N; j++)
		{
			if (m[i][j] == 'P')
				s = make_pair(i,j);
			else if (m[i][j] == 'K')
				v.push_back(make_pair(i,j));
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			c[i][j] = -1;
			scanf("%d", &a[i][j]);
		}
	}

	int minv, maxv;
	minv = maxv = a[s.first][s.second];

	for (int i = 0; i < v.size(); i++)
	{
		int val = a[v[i].first][v[i].second];
		minv = min(val, minv);
		maxv = max(val, maxv);
	}

	int left = maxv - minv, right = 1000001;

	while (left != right + 1)
	{
		int mid = left + right; mid /= 2;
		bool isPossible = false;

		for (int i = 0; i < N && !isPossible; i++)
		{
			for (int j = 0; j < N && !isPossible; j++)
			{
				nowChk = N*i + j;

				int minPick = a[i][j];
				int maxPick = minPick + mid;
				if (minPick <= minv && maxv <= maxPick)
				{
					k = 0;
					status.min = minPick;
					status.max = maxPick;

					if (godp(s.first, s.second))
						isPossible = true;
				}
			}
		}

		if (isPossible)
			right = mid - 1;
		else
			left = mid + 1;
	}

	cout << left;
}

