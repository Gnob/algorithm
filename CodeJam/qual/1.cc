#include<iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)	
	{
		long long N;
		cin >> N;

		if (N == 0)
		{
			printf("Case #%d: ", t);
			cout << "INSOMNIA\n";
			continue;
		}

		bool digit[10] = { false, };

		int cnt = 0;
		long long nowSheep = N;
		bool isSleep = false;

		while (!isSleep)
		{
			cnt++;
			nowSheep = N * cnt;
			long long tmp = nowSheep;

			while (tmp)
			{
				digit[tmp % 10] = true;
				tmp /= 10;
			}

			isSleep = true;
			for (int i = 0; i < 10; i++)
			{
				if (!digit[i])
				{
					isSleep = false;
					break;
				}
			}
		}

		// output
		printf("Case #%d: ", t);
		cout << nowSheep << '\n';
	}
}
