#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

vector<string> v;

int main()
{
	int N, M;
	cin >> N >> M;

	string buf;
	unordered_map<string, int> hash;

	for (int i = 0; i < N; i++)
	{
		cin >> buf;
		hash[buf] += 1;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> buf;
		
		if (hash.find(buf) != hash.end())
			v.push_back(buf);
	}

	sort(v.begin(), v.end());

	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';
}
