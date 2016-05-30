#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

unsigned long long a[11];

string printBinary(const unsigned long long &x)
{
	string buf = "";
	unsigned long long tmp = x;

	while (tmp)
	{
		if ((tmp & 1) == 1)
			buf.push_back('1');
		else
			buf.push_back('0');

		tmp >>= 1;
	}

	reverse(buf.begin(), buf.end());

	return buf;
}

bool checkPrime(const unsigned long long &x, int base)
{
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			a[base] = i;
			return false;
		}
	}

	return true;
}

unsigned long long generateCandidate(const int &N, const long long &token)
{
	unsigned long long result = (1 << (N - 1)) | 1;
	unsigned int bitmask = (1 << N) - 2;
	result |= ((token << 1) & bitmask);
	return result;
}

bool isValidJamcoin(const unsigned long long &coin)
{
	for (int base = 2; base <= 10; base++)
	{
		unsigned long long tmp = coin;
		unsigned long long result = 0;
		unsigned long long mult = 1;

		while (tmp)
		{
			if ((tmp & 1) == 1)
			{
				result += mult;
			}

			mult *= base;
			tmp >>= 1;
		}

		if (checkPrime(result, base))
			return false;

		// a[base] = result;
	}

	return true;
}

unsigned long long generateJamcoin(const int &N, const long long &seq)
{
	unsigned long long coin = generateCandidate(N, seq);

	if (isValidJamcoin(coin))
		return coin;

	return -1;
}

int main() 
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int N, J;
		cin >> N >> J;


		// output	
		printf("Case #%d:\n", t);
		for (int k = 2; k <= J + 1; k++)
		{
			unsigned long long coin = generateJamcoin(N, k);
			if (coin == -1)
			{
				J++;
				continue;
			}

			cout << printBinary(coin);
			for (int i = 2; i <= 10; i++) cout << ' ' << a[i];
			printf("\n");
		}
	}
}

