#include <iostream>

using namespace std;

typedef unsigned long long ull;
ull d[50];

bool is_m;

ull fast_pow(ull a, ull n)
{
	ull ans = 1;
	while (n > 0)
	{
		if (n % 2 == 1) ans *= a;
		n /= 2;
		a *= a;
	}
	return ans;
}

void find_ch(ull N)
{
	int seq;
	for (seq = 0; seq < 28; seq++)
		if (N <= d[seq])
			break;
	
	if (seq == 0)
	{
		if (N == 1)
			is_m = true;
		return;
	}

	if (d[seq - 1] < N && N <= d[seq - 1] + seq + 3)
	{
		if (N == d[seq - 1] + 1)
			is_m = true;
		return;
	}
	else if (d[seq - 1] + seq + 3 < N)
		N -= d[seq - 1] + seq + 3;

	find_ch(N);
}

int main()
{
	d[0] = 3;
	for (int i = 1; i < 50; i++)
		d[i] = d[i - 1] + fast_pow(2, i + 2) - 1;

	int N;
	cin >> N;
	find_ch(N);

	cout << (is_m ? 'm' : 'o');
}
