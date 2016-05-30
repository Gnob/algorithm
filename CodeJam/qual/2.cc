#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() 
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		string buf;
		cin >> buf;

		int ref = 0, cur = 0;
		int cnt = 0;

		for (int cur = 0; cur < buf.size(); cur++)
		{
			if (buf[ref] != buf[cur])
			{
				cnt++;
				ref = cur;
			}
		}

		if (buf[ref] == '-') cnt++;
		
		// output	
		printf("Case #%d: ", t);
		cout << cnt << '\n';
	}
}

