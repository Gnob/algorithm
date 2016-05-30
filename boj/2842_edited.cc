#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

char m[50][50];
int a[50][50];
int d[50][50];
bool c[50][50];

int N;
int k;
pair<int,int> s;
vector< pair<int,int> > v;
int dir[8][2] = {
	{ 1, 0 }, { 1, 1 }, { 0, 1 }, { -1, 1 },  
	{ -1, 0 }, { -1, -1 }, { 0, -1 }, { 1, -1 }   
};

//int dir[8][2] = {
//	{ -1, -1 }, { 0, -1 }, { 1, -1 }, { -1, 0 }, { 1, 0 }, { -1, 1 }, { 0, 1 } , { 1, 1 } 
//};

struct {
	int min;
	int max;
} status;

bool bfs()
{
	queue< pair<int,int> > q;

	c[s.first][s.second] = true; 
	q.push(s);

	while (!q.empty())
	{
		pair<int,int> now = q.front();
		q.pop();

		int x = now.first;
		int y = now.second;

		for (int i = 0; i < 8; i++)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (0 <= nx && nx < N && 0 <= ny && ny < N && !c[nx][ny]) 
			{
				if (status.min <= a[nx][ny] && a[nx][ny] <= status.max)
				{
					if (m[nx][ny] == 'K') k++; 
					if (k == v.size())
						return true;
					c[nx][ny] = true; 
					q.push(make_pair(nx,ny));
				}
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

    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());

	int mina, maxa;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &a[i][j]);

			if (i == 0 && j == 0)
				mina = maxa = a[i][j];
			else
			{
				mina = min(mina, a[i][j]); 
				maxa = max(maxa, a[i][j]); 
			}
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

	int left = maxv - minv, right = maxa - mina;

	while (left != right + 1)
	{
		int mid = left + right; mid /= 2;
		bool isPossible = false;

		for (int i = 0; i < N && !isPossible; i++)
		{
			for (int j = 0; j < N && !isPossible; j++)
			{
				memset(c, 0, sizeof(c));

				int minPick = a[i][j];
				int maxPick = minPick + mid;
				if (minPick <= minv && maxv <= maxPick)
				{
					k = 0;
					status.min = minPick;
					status.max = maxPick;

					if (bfs()) isPossible = true;
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

