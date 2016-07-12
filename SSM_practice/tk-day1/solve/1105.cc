#include <iostream>
#include <string>

using namespace std; 

int main()
{
	string L, R;

	cin >> L >> R;

	if (L.length() != R.length())
		cout << 0;
	else
	{
		int idx = 0, cnt = 0;;
		while (L[idx] == R[idx])
		{
			if (L[idx] == '8') 
				cnt++;
			idx++;
		}
		cout << cnt;
	}
}
