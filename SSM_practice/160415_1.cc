/*

VCPP, GPP에서 사용

*/

#include <iostream>
#include <string>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for(int itr=0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr+1) << endl;

		string buf;
		
		cin >> buf;

		int cnt = 0;

		for (int i = 1; i < buf.size(); i++)
		{
			if (buf[i - 1] != buf[i])
				cnt++;
		}

		if (buf.front() == '1') cnt++;

		cout << cnt << '\n';
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}
