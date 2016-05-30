#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> m;
vector<int> p(10001);
bool chk[202][202];

int N, M;
double K;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0 ,-1 };
int ddx[] = { -2, 0, 2, 0 };
int ddy[] = { 0, 2, 0 ,-2 };

int find_set(int x)
{
	if (x == p[x])
		return x;

	return p[x] = find_set(p[x]);
}

void union_set(int x, int y)
{
	p[find_set(x)] = y;
}

void make_block(int x, int y)
{
	chk[x / 2 + y / 2 * N] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		int nnx = x + ddx[i];
		int nny = y + ddy[i];
		if (0 <= nnx  && nnx <= 2*M + 1 && 0 <= nny  && nny <= 2*N + 1)
		{
			if (m[nx][ny] == '.' && !chk[nnx][nny])
			{
				union_set(x / 2 + y / 2 * N, nx / 2 + ny / 2 * N);
				make_block(nnx, nny);
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	cin >> K;

	string buf;

	for (int i = 0; i < M; i++)
	{
		cin >> buf;
		m.push_back(buf);
	}

	for (int i = 1; i <= 2*M + 1; i+=2)
	{
		for (int j = 1; j <= 2*N + 1; j+=2)
		{
			if (m[i][j] == 'B' && !chk[i][j])
				make_block(i, j);
		}
	}
	
	d

}
