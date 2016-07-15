#include <iostream>
#include <vector>
#include <queue>

int main()
{
	int N, M;

	std::cin >> N >> M;

	int infinite = 200000000;
	std::vector<std::vector<int>> graph(1 + N, std::vector<int>(1 + N, infinite));

	for (int i = 0; i < M; i++)
	{
		int from, to, weight;
		std::cin >> from >> to >> weight;
		graph[from][to] = std::min(graph[from][to], weight);
	}

	for (int i = 1; i <= N; i++)
		graph[i][i] = 0;

	std::vector<std::vector<int>> floyd(graph);
	std::vector<std::vector<std::queue<int>>> seq(1 + N, std::vector<std::queue<int>>(1 + N));

	for (int turn = 1; turn <= N; turn++)
	{
		for (int updater = 1; updater <= N; updater++)
		{
			if (updater != turn && floyd[updater][turn] != infinite)
			{
				for (int to = 1; to <= N; to++)
				{
					if (turn != to && updater != to && floyd[turn][to] != infinite)
					{
						floyd[updater][to] = std::min(floyd[updater][to],
								floyd[updater][turn] + floyd[turn][to]);
						seq[updater][to].push(turn);
					}
				}
			}

		}
	}



	for (int from = 1; from <= N; from++)
	{
		for (int to = 1; to <= N; to++)
			std::cout << floyd[from][to] << " ";
		std::cout << '\n';
	}

	for (int from = 1; from <= N; from++)
	{
		for (int to = 1; to <= N; to++)
		{
			std::cout << seq[from][to].size() << ' ';

			if (seq[from][to].empty())
			{
				std::cout << '\n';
				continue;
			}

			std::cout << from << ' ';
			while (!seq[from][to].empty())
			{
				std::cout << seq[from][to].front() << " ";
				seq[from][to].pop();
			}

			std::cout << to << '\n';
		}
		std::cout << '\n';
	}
}

