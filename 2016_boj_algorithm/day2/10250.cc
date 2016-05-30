#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int T;
	int H, W, S;
	int q, r;

	cin >> T;

	while (T--)
	{
		scanf("%d %d %d", &H, &W, &S);
		
		q = S / H;
		r = S % H;

		if (S % H == 0)
		{
			q--;
			r = H;
		}
		printf("%d%02d\n", r, q + 1);
	}
}

