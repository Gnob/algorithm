#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

vector<ull> v;

void generate_kms(int before, ull now, int cnt)
{
	if (cnt == 10)
	{
		v.push_back(now);
		return;
	}

	if (before == 0)
		generate_kms(0, now * 10 + 0, cnt + 1);
	generate_kms(4, now * 10 + 4, cnt + 1);
	generate_kms(7, now * 10 + 7, cnt + 1);
}

int main()
{
	generate_kms(0, 0, 0);
	
	ull A, B;
	cin >> A >> B;

	int cnt = 0;
	for (int i = 0; i < v.size(); i++)
		if (A <= v[i] && v[i] <= B)
			cnt++;
	cout << cnt;
}
