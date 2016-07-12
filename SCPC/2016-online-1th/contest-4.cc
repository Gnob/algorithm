#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int to;
    unsigned long long cost;
    Edge(int to, unsigned long long cost) : to(to), cost(cost) {
    }
};

vector<Edge> a[100001];
unsigned long long dist[100001];
bool check[100001];
bool dp[100001];
int p[100001];
unsigned long long inf = 10000000000000000000UL;

int find_dps(int x)
{
	if (p[x] == x)
		return x;

	return p[x] = find_dps(p[x]);
}

int main(int argc, char** argv) {
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	   만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	   그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	   또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	   단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	//freopen("input.txt", "r", stdin);

	/* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	   C++에서 printf를 사용할 경우, printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
	   따라서 printf를 사용할 경우 setbuf(stdout, NULL) 함수를 반드시 사용하시기 바랍니다. */
	setbuf(stdout, NULL);

	int T;
	int test_case;
    
	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for(test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
		int N, M, K;
		scanf("%d %d %d", &N, &M, &K);

		for (int i = 0; i <= N; i++)
		{
			dp[i] = false;
			a[i].clear();
			dist[i] = inf;
			check[i] = false;
			p[i] = i;
		}

		for (int i = 0; i < M; i++) 
		{
			int src, dst ,cost;
			scanf("%d %d %d", &src, &dst, &cost);
			a[src].push_back(Edge(dst, cost));
			a[dst].push_back(Edge(src, cost));
		}


		for (int i = 0; i < K; i++)
		{
			int dps_id;
			scanf("%d", &dps_id); 
			dp[dps_id] = true;
			a[0].push_back(Edge(dps_id, 0));
		}

		int ans_sum_dps = 0;
		unsigned long long ans_sum_dist = 0;

		int start = 0;
		dist[start] = 0;

		priority_queue< pair<unsigned long long, int>,
			vector<pair<unsigned long long, int> >,
			greater<pair<unsigned long long, int> > > q;

		for (int i = 0; i < a[start].size(); i++) 
		{
			int dst = a[start][i].to;
			dist[dst] = 0;
			q.push(make_pair(dist[dst], dst));
		}

		while (!q.empty()) 
		{
			pair<unsigned long long, int> now = q.top();
			q.pop();

			int src = now.second;

			if (now.first != 0 && (dp[src] || check[src])) 
				continue;

			check[src] = true;
			for (int i = 0; i < a[src].size(); i++) 
			{
				int dst = a[src][i].to;
				if (!dp[dst] && dist[dst] >= dist[src] + a[src][i].cost) 
				{
					if (dist[dst] == dist[src] + a[src][i].cost && find_dps(src) >= find_dps(dst))
						continue;

					dist[dst] = dist[src] + a[src][i].cost;
					p[dst] = src;
					q.push(make_pair(dist[dst], dst));
				}
			}
		}

		for (int i = 1; i <= N; i++)
		{
			ans_sum_dist += dist[i];
			ans_sum_dps += find_dps(i);
		}

		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);
		printf("%llu\n%d\n", ans_sum_dist, ans_sum_dps);
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
