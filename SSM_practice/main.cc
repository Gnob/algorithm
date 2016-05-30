#include <cstdio>
#include <iostream>

using namespace std;

long long robot[100000];

int main(int argc, char** argv) {
	int TC;
    int test_case;
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	   만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	   그 아래에서 cin 을 사용하여 표준 입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	   따라서 본인의 PC 에서 테스트 할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 됩니다.
	   단, 이 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다. */
	//freopen("input.txt", "r", stdin);

	cin >> TC;
    for(test_case = 1; test_case <= TC; ++test_case) {
		int N, R, S;
		cin >> N >> R >> S;

		for (int i = 0; i < N; i++)
		{
			scanf("%lld", &robot[i]);
		}

		if (N * R * 2 < S)
		{
			cout << "Case #" << test_case << endl;
			printf("-1\n");
			continue;
		}
		
		long long left = 0, right = 1000000001L;
		long long minDistance = 1000000000L;
		
		while (left != right + 1)
		{
			long long mid = left + right;
			mid /= 2;
			long long target = 0;

			int i;
			bool isPossible = false;
			for (i = 0; i < N; i++)
			{
				long long now = robot[i];

				if (now < target) {
					if (target <= now + mid)
					{
						long long pos = min(now + mid, target + R);
						target = pos + R;
					}
				}
				else {
					if (target + R >= now - mid)
					{
						long long pos = max(now - mid, target + R);
						target = pos + R;
					}
					else {
						isPossible = false;
						break;
					}
				}
				if (target >= S) {
					isPossible = true;
					break;
				}
			}
			if (!isPossible)
				left = mid + 1;
			else
			{
				minDistance = min(minDistance, mid);
				right = mid - 1;
			}
		}
        
		//	이 부분에서 정답을 출력하십시오.  
		cout << "Case #" << test_case << endl;
		cout << left << endl;
	}

	return 0;	//	정상종료 시 반드시 0을 리턴해야 합니다.
}
