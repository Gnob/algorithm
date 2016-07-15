#include <cstdio>
#include <iostream>

using namespace std;

unsigned long long d[50001][101];
bool is_mine[50001];

int main(int argc, char** argv) {
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	   만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	   그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	   또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	   단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	//freopen("input.txt", "r", stdin);

	/* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	   C++에서 printf를 사용할 경우, printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
	   따라서 printf를 사용할 경우 setbuf(stdout, NULL) 함수를 반드시 사용하시기 바랍니다. */
	setbuf(stdout, NULL);

	int T;
	int test_case;
    
	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for(test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
        
		int N, K, L;
		scanf("%d %d %d", &N, &K, &L);

		if (K > 1)
		{
			for (int i = 0; i <= N; i++) 
			{
				is_mine[i] = false;
				for (int j = 0; j <= K; j++)
					d[i][j] = 0;
			}
		}

		for (int i = 1; i <= L; i++)
		{
			int idx;
			scanf("%d", &idx);
			is_mine[idx] = true;
		}

		unsigned long long ans = 0;
		if (K > 1)
		{
			for (int j = 1; j <= K; j++)
			{
				if (is_mine[j])
					d[j][j] = 0;
				else 
					d[j][j] = 1;
			}

			for (int j = 1; j <= K; j++)
				d[1][0] += d[1][j];

			for (int i = 2; i <= N; i++)
			{
				if (is_mine[i])
					continue;

				int bound = i < K ? i - 1: K;

				for (int now = 1; now <= bound; now++)
				{
					int pre_i = i - now;

					if (!is_mine[pre_i] && pre_i > 0)
					{
						d[i][now] = d[pre_i][0] - d[pre_i][now];
						d[i][now] += 1000000009;
						d[i][now] %= 1000000009;
					}
				}

				for (int j = 1; j <= K; j++)
					d[i][0] += d[i][j];
			}

			for (int i = 1; i <= K; i++)
				ans += d[N][i];
		}
        
		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);
		cout << ans % 1000000009 << '\n';
        
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
