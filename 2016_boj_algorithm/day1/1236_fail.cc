// 문제를 잘 못 이해 했었음
// 행과 열에 존재하는게 중요한거지
// 그 행이 지켜지고 있느냐? 이런 문제가 아님 
#include<iostream>
#include<vector>

using namespace std;

int N, M;

void fill(vector<string> &v, int x, int y)
{
	for (int i = 0; i < N; i++)
	{
		if (v[i][y] == '.')
			v[i][y] = 'O';
	}
	for (int i = 0; i < M; i++)
	{
		if (v[x][i] == '.')
			v[x][i] = 'O';
	}
}


void init(vector<string> &v)
{
	for (int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if (v[i][j] == 'X') fill(v, i, j);
		}
	}
}

int main()
{
	cin >> N >> M;

	vector<string> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	init(v);

	int cnt = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (v[i][j] == '.') {
				v[i][j] = 'x';
				fill(v, i, j);
				cnt++;
			}
		}
	}

	cout << cnt;
}

