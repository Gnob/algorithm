#include <iostream>
#include <vector>

std::vector<std::vector<int>> 
	transitive_closure_floyd(const std::vector<std::vector<int>> &origin_graph);

int main()
{
	int N, M;

	std::cin >> N >> M;

	std::vector<std::vector<int>> graph(1 + N, std::vector<int>(1 + N));

	for (int i = 0; i < M; i++)
	{
		int from, to;
		std::cin >> from >> to;
		graph[from][to] = 1;
	}

	std::vector<std::vector<int>> &&transitive_graph 
		= transitive_closure_floyd(graph);

	for (int from = 1; from <= N; from++)
	{
		std::cout << "now vertax is " << from << std::endl;
		for (int to = 1; to <= N; to++)
			if (transitive_graph[from][to])
				std::cout << from << "->" << to << " is reachable." << std::endl;
	}

}

std::vector<std::vector<int>> 
	transitive_closure_floyd(const std::vector<std::vector<int>> &origin_graph)
{
	int N = origin_graph.size() - 1;

	std::vector<std::vector<int>> transitive_graph(origin_graph);

	for (int turn_idx = 1; turn_idx <= N; turn_idx++)
	{
		for (int updater = 1; updater <= N; updater++)
		{
			if (turn_idx == updater || !transitive_graph[updater][turn_idx])
				continue;

			for (int idx = 1; idx <= N; idx++)
				if (transitive_graph[turn_idx][idx])
					transitive_graph[updater][idx] = 1;
		}
	}

	return transitive_graph;
}
