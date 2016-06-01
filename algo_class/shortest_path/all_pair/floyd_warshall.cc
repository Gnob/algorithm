#include <iostream>
#include <vector>
#include <stack>

std::vector<std::vector<int>>
	get_shortest_distance(const std::vector<std::vector<int>> &origin_graph);

int main()
{
	int N, M;

	std::cin >> N >> M;

	std::vector<char> verticles(1 + N);
	for (int i = 1; i <= N; i++)
		verticles[i] = 'A' - 1 + i;

	std::vector<std::vector<int>> graph(1 + N, std::vector<int>(1 + N));

	for (int i = 0; i < M; i++)
	{
		int from, to, weight;
		std::cin >> from >> to >> weight;
		graph[from][to] = weight;
		graph[to][from] = weight;
	}

	std::vector<std::vector<int>> &&shortest_graph = get_shortest_distance(graph);

	std::stack<int> dfs_stack;

	for (int starter = 1; starter <= N; starter++)
	{
		std::vector<bool> check(1 + N, false);

		std::cout << "now vertax is " << verticles[starter] << std::endl;

		check[starter] = true;

		for (int to = 1; to <= N; to++)
			if (starter != to && shortest_graph[starter][to])
				dfs_stack.push(to);

		while (!dfs_stack.empty())
		{
			int now = dfs_stack.top(); dfs_stack.pop();

			if (check[now]) continue;

			check[now] = true;

			std::cout << verticles[starter] << "->" << verticles[now] << " / "
				<< shortest_graph[starter][now] << std::endl;

			for (int to = 1; to <= N; to++)
				if (now != to && !check[to] && shortest_graph[now][to])
					dfs_stack.push(to);
		}
	}
}

std::vector<std::vector<int>>
	get_shortest_distance(const std::vector<std::vector<int>> &origin_graph)
{
	int N = origin_graph.size() - 1;
	std::vector<std::vector<int>> shortest_graph(origin_graph);

	for (int turn_idx = 1; turn_idx <= N; turn_idx++)
	{
		for (int updater = 1; updater <= N; updater++)
		{
			if (turn_idx == updater || !shortest_graph[updater][turn_idx])
				continue;

			for (int idx = 1; idx <= N; idx++)
			{
				if (shortest_graph[turn_idx][idx])
				{
					if (shortest_graph[updater][idx])
					{
						shortest_graph[updater][idx] =
							std::min(shortest_graph[updater][idx],
									shortest_graph[updater][turn_idx] +
										shortest_graph[turn_idx][idx]);
					}
					else
						shortest_graph[updater][idx] =
									shortest_graph[updater][turn_idx] +
										shortest_graph[turn_idx][idx];
				}
			}
		}
	}

	return shortest_graph;
}
