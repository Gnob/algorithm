#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int N;
	vector< pair<int, string> > v;
	cin >> N;

	while (N--)
	{
		string buf;
		cin >> buf;
		v.push_back(make_pair(buf.length(), buf));
	}

	sort(v.begin(), v.end());

	cout << v[0].second << '\n';
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i-1].second == v[i].second) continue;
		cout << v[i].second << '\n';
	}
}

