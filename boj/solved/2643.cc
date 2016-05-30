#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int,int> pii;

vector<pii> v;

int main()
{
	int N;

	cin >> N;

	vector<int> d(N);

	for (int i = 0; i < N; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		if (a < b) 
			v.push_back(make_pair(b, a));
		else
			v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end());
		
	int left = 0, right = 1;
	int ans = 1;

	for (int i = 0; i < N; i++)
	{
		d[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (v[j].second <= v[i].second && d[i] < d[j] + 1)	
				d[i] = d[j] + 1;
		}
	}

	sort(d.begin(), d.end());

	cout << d.back();
}
