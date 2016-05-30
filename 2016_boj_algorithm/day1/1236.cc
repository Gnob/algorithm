#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	set<int> row, col;
	vector<string> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (v[i][j] == 'X')
			{
				row.insert(i);
				col.insert(j);
			}
		}
	}

	int cntRow = N - row.size();
	int cntCol = M - col.size();

	if (cntRow > cntCol)
		cout << cntRow;
	else
		cout << cntCol;

}
