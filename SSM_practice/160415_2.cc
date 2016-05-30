/*

VCPP, GPP에서 사용

*/
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

const ll C = 1000000;

struct Edge 
{
	int s;
	int e;
	ll v;
	ll l;
	ll t;
	ll d;
};

int N, M, D;
int S, E, V, L;
ll ans;

vector< vector<Edge> > a(151), b(151);
vector<int> route, tmp;

void dfs(const int &now, const ll &spd, const ll &cost)
{
	if (now == D)
	{
		route = tmp;
		route.push_back(now);
		ans = min(ans, cost);
		return;
	}

	int len = a[now].size();
	ll nextCost = cost;
	
	tmp.push_back(now);

	for (int i = 0; i < len; i++)
	{
		nextCost = cost;

		if (a[now][i].t == 0)
			nextCost += (a[now][i].l * C) / spd;
		else
			nextCost += a[now][i].t;

		if (nextCost < a[now][i].d)
		{
			a[now][i].d = nextCost;
			dfs(a[now][i].e, a[now][i].t == 0 ? spd : a[now][i].v, nextCost);
		}
	}

	tmp.pop_back();
}

int main()
{
	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for(int itr=0; itr < nCount; itr++)
	{
		ans = 0x7FFFFFFFFFFFFFFF;
		cout << "#testcase" << (itr+1) << endl;

		scanf("%d %d %d", &N, &M, &D);

		route.clear();
		tmp.clear();
		a.clear();
		a.resize(M);

		for (int i = 0; i < M; i++)
		{
			scanf("%d %d %d %d", &S, &E, &V, &L);

			Edge v = { S, E, V, L, V == 0 ? 0 : (L * C) / V, ans };
			a[S].push_back(v);
		}

		dfs(0, 70, 0);

		for (int i = 0; i < route.size(); i++)
			printf("%d ", route[i]);

		printf("\n");
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 
}
