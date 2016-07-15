#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

#define one first
#define two second
#define x first
#define y second

using namespace std;
typedef unsigned long long ull;
typedef pair<ull, ull> pii;
typedef pair<pair<ull, ull>, int > ppi;
typedef pair<pair<ull, ull>, pair<ull, ull> > ppp;

ppp m[5001];
vector<ppi> v;

int main()
{
	setbuf(stdout, NULL);

	int T;
	int test_case;
	int N, M, K;
	cin >> T;

	for(test_case = 1; test_case <= T; test_case++) 
	{
		cin >> N >> M >> K;

		vector<ull> d(K);
		v.clear();

		for (int i = 0; i < K; i++)
		{
			ull a, b, c, d;
			scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

			v.push_back(make_pair(make_pair(c-a, d-b), i));
			m[i].one.x = a;
			m[i].one.y = b;
			m[i].two.x = c;
			m[i].two.y = d;
		}

		sort(v.begin(), v.end());

		int ans = 1;

		for (int i = 0; i < K; i++)
		{
			d[i] = 1;
			for (int j = 0; j < i; j++)
			{
				if (m[v[i].two].one.x <= m[v[j].two].one.x && m[v[j].two].one.x < m[v[j].two].two.x
						&& m[v[j].two].two.x <= m[v[i].two].two.x && m[v[i].two].one.y <= m[v[j].two].one.y
						&& m[v[j].two].one.y < m[v[j].two].two.y && m[v[j].two].two.y <= m[v[i].two].two.y 
						&& v[j].one.two <= v[i].one.two && d[i] < d[j] + 1)	
					d[i] = d[j] + 1;
			}
		}

		sort(d.begin(), d.end());

		printf("Case #%d\n", test_case);
		printf("%lld\n", d.back());
	}

	return 0;
}

