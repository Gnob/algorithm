#include <cstdio>
#include <iostream>

using namespace std;

const long long cons = 1000000000L;
long long c[6] = { 0, 1 * cons, 2 * cons, 3 * cons, 4 * cons, 5 * cons }; 

int cdiv[3][10] = {
	{ 1, 1, 2, 1, 5, 2, 1, 1, 5, 1 },
	{ 1, 1, 2, 1, 4, 2, 1, 1, 4, 1 },
	{ 1, 1, 2, 1, 4, 2, 1, 1, 8, 1 }
};

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
		double P;
		cin >> P;
		
		long long target = (long long)(P * cons);
		long long tmp = target, n = cons;
		long long ans[6];
		long long left = 1, right = 10000000000000000L; 
		long long min = 100000000000L;

		int digit = 0;
		for (int i = 0; i < 9; i++)
		{
			digit = tmp % 10;
			if (tmp % 10 != 0)
				break;
			
			tmp /= 10;
			n /= 10;
		}

		int k = 0;
		if (n == 10)
			k = 0;
		if (n == 100)
			k = 1;
		if (n == 1000)
			k = 2;
		n /= cdiv[k][digit];

		long long maxDigit = int(P);
		long long sum = target * n;
		long long result = maxDigit * n;
		long long x = 0;
		while (result != sum)
		{
			x++;
			result = maxDigit*(x) + (maxDigit+1)*(n-x); 
		}
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
