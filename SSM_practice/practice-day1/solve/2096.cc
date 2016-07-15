#include <iostream>

using namespace std;

int main()
{
	int dmax[2][3];
	int dmin[2][3];

	int N; cin >> N;

	int pre = 1, now = 0;
	N--;

	cin >> dmax[now][0] >> dmax[now][1]>> dmax[now][2];
	dmin[now][0] = dmax[now][0];	
	dmin[now][1] = dmax[now][1];	
	dmin[now][2] = dmax[now][2];	

	while (N--)
	{
		pre = (pre + 1) % 2;
		now = (now + 1) % 2;

		cin >> dmax[now][0] >> dmax[now][1]>> dmax[now][2];

		dmin[now][0] = dmax[now][0];	
		dmin[now][1] = dmax[now][1];	
		dmin[now][2] = dmax[now][2];	

		dmin[now][0] += min(dmin[pre][0], dmin[pre][1]);
		dmin[now][1] += min(min(dmin[pre][0], dmin[pre][1]), dmin[pre][2]);
		dmin[now][2] += min(dmin[pre][2], dmin[pre][1]);

		dmax[now][0] += max(dmax[pre][0], dmax[pre][1]);
		dmax[now][1] += max(max(dmax[pre][0], dmax[pre][1]), dmax[pre][2]);
		dmax[now][2] += max(dmax[pre][2], dmax[pre][1]);
	}

	cout << max(max(dmax[now][0], dmax[now][1]), dmax[now][2]) << ' ' << min(min(dmin[now][0], dmin[now][1]), dmin[now][2]);
}

