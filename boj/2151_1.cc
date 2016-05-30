#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

typedef pair<int,int> pii;

struct Status {
	int cnt;
	pii dir;
};

int N;
pii s, e;
vector<pii> m;
char v[101][101];

int result = 100000000;

bool dfs(const int &x, const int &y, const Status &stat)
{
	/*
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (x == i && y == j)
				cout << '@';
			else
				cout << v[i][j];
		}
		cout << endl;
	}
	cout << endl;
	*/
	if (v[x][y] == '*' || result <= stat.cnt) return false;

	if (e.first == x && e.second == y) 
	{
		result = stat.cnt;
		return true;
		//result = min(result, stat.cnt);
		//return;
	}

	int dx = stat.dir.first;
	int dy = stat.dir.second;

	int nx, ny;

	nx = x + stat.dir.first;
	ny = y + stat.dir.second;
	if (0 <= nx && nx < N && 0 <= ny && ny < N)
		if(dfs(nx, ny, stat))
			return true;

	if (v[x][y] == '!')
	{
		Status lStat = { stat.cnt + 1, make_pair(dy, -dx) };
		nx = x + lStat.dir.first;
		ny = y + lStat.dir.second;
		if (0 <= nx && nx < N && 0 <= ny && ny < N)
			if(dfs(nx, ny, lStat))
				return true;

		Status rStat = { stat.cnt + 1, make_pair(-dy, dx) };
		nx = x + rStat.dir.first;
		ny = y + rStat.dir.second;
		if (0 <= nx && nx < N && 0 <= ny && ny < N)
			if(dfs(nx, ny, rStat))
				return true;
	}
	
	return false;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> v[i];

	int cnt = 0;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
	{
		if (v[i][j] == '#')
		{
			if (cnt == 0) s = make_pair(i, j);
			else e = make_pair(i, j);
			cnt++;
		}
		
		if (v[i][j] == '!')
			m.push_back(make_pair(i, j));
	}

	pii dir;
	if (s.first == 0) dir = make_pair(1, 0);
	else if (s.first == N - 1) dir = make_pair(-1, 0);
	else if (s.second == 0) dir = make_pair(0, 1);
	else if (s.second == N - 1) dir = make_pair(0, -1);
	Status stat = { 0, dir };

	dfs(s.first, s.second, stat);

	cout << result;
}

