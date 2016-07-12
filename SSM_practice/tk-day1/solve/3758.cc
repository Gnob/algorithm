#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef pair< pair<int, pii>, int > ppip;

int score[101][101];
int cnt[101];
int t[101];
int total[101];

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		for (int i = 0; i <= 100; i++)
		{
			for (int j = 0; j <= 100; j++)
				score[i][j] = 0;
			cnt[i] = 0;
			t[i] = 0;
			total[i] = 1;
		}

		int N, K, T, M;
		cin >> N >> K >> T >> M;

		for (int i = 1; i <= M; i++)
		{
			int tid, pid, s;
			cin >> tid >> pid >> s;

			score[tid][pid] = max(s, score[tid][pid]);
			t[tid] = i;
			cnt[tid]++;
		}

		for (int j = 1; j <= N; j++)
			for (int i = 1; i <= K; i++)
				total[j] += score[j][i];

		vector<ppip> v(0);

		for (int i = 1; i <= N; i++)
			v.push_back(make_pair(make_pair(-total[i], make_pair(cnt[i], t[i])), i));

		sort(v.begin(), v.end());

		int ans = 0;
		for (int i = 0; i < v.size(); i++)
			if (v[i].second == T)
				ans = i + 1;

		cout << ans << '\n';
	}
}
