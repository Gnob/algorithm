// DFS 피로도로 Branch cut 하는 것은 너무 느리다.
#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

char m[50][50];
int a[50][50];
int d[50][50];
bool c[50][50];

int N;
pair<int,int> s;
vector< pair<int,int> > v;
int dir[8][2] = {
	{ 1, 0 }, { 1, 1 }, { 0, 1 }, { -1, 1 },  
	{ -1, 0 }, { -1, -1 }, { 0, -1 }, { 1, -1 }   
};

struct Status {
	int maxStress;
	int min;
	int max;
	int k;
};

bool godp(const int &x, const int &y, const Status &now)
{
	if (now.k == v.size())
		return true;

	c[x][y] = true;
	for (int i = 0; i < 8; i++)
	{
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (0 <= nx && nx < N && 0 <= ny && ny < N && !c[nx][ny]) 
		{
			int minv = min(a[nx][ny], now.min);
			int maxv = max(a[nx][ny], now.max);
			int stress = maxv - minv;
			
			if (now.maxStress >= stress)
			{
				int nk = now.k;
				if (m[nx][ny] == 'K') nk++; 
				Status next = { now.maxStress, minv, maxv, nk };
				if (godp(nx, ny, next))
				{
					c[x][y] = false;
					return true;
				}
			}
		}
	}
	c[x][y] = false;

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

		Status now = { mid, minv, maxv, 0 };

		bool isPossible = godp(s.first, s.second, now);

		if (isPossible)
			right = mid - 1;
		else
			left = mid + 1;
	}

	cout << left;
}

