#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
{
	int start;
	int end;
	int cost;
	int capacity;
	Item(int s, int e, int c, int capacity) :start(s), end(e), cost(c), capacity(capacity) {}
};

bool cmp(const Item &lhs, const Item &rhs)
{
	return lhs.capacity < rhs.capacity;
}

bool item_timetable[200][100];
vector<bool> blocks[100];
vector<Item> v;

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
	
		int N, K;
		cin >> N >> K;

		int max_end = 0;
		int min_start = 100;
		v.clear();

		for (int i = 0; i < N; i++)
			for (int j = 0; j < 100; j++)
				item_timetable[i][j] = false;

		for (int i = 0; i < N; i++)
		{
			int start, end, cost;
			cin >> start >> end >> cost;
			v.push_back(Item(start, end, cost, end - start));

			min_start = min(min_start, start);
			max_end = max(max_end, end);
		}

		sort(v.begin(), v.end(), cmp);

		for (int i = 0; i < N; i++)
			for (int j = v[i].start; j < v[i].end; j++)
				item_timetable[i][j] = true;


		for (int i = 0; i < max_end; i++)
			blocks[i].clear();

		for (int i = 0; i < K; i++)
		{
			int start, end;
			cin >> start >> end;
			for (int j = start; j < end; j++)
				blocks[j].push_back(true);

			min_start = min(min_start, start);
			max_end = max(max_end, end);
		}
		// cout << min_start << '/' << max_end << endl;

		bool is_possible = true;

		for (int i = min_start; i < max_end; i++)
		{
			int cnt = 0;
			for (int j = 0; j < N; j++)
			{
				if (item_timetable[j][i])
					cnt++;
			}

			// cout << "Now time is @" << i << " item need #" << cnt << endl;
			// cout << "I have worker #" << blocks[i].size() << endl;

			bool is_changed = true;
			while (blocks[i].size() < cnt)
			{
				is_changed = false;

				for (int j = 0; j < N; j++)
				{
					if (item_timetable[j][i] && v[j].capacity > v[j].cost)
					{
						is_changed = true;
						item_timetable[j][i] = false;
						v[j].capacity--;
						cnt--;

						/*
						for (int x = 0; x < N; x++)
						{
							for (int y = min_start; y < max_end; y++)
								cout << item_timetable[x][y];
							cout << endl;
						}
						cout << endl;
						*/

						if (blocks[i].size() == cnt)
							break;
					}
				}

				if (!is_changed) 
					break;
			}

			if (blocks[i].size() < cnt && !is_changed)
			{
				// cout << "Impossible" << endl;
				is_possible = false;
				break;
			}
		}

		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);
        cout << is_possible << '\n';
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
