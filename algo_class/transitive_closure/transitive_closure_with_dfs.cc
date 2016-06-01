#include <iostream>
#include <vector>
#include <list>

struct Edge
{
	int from, to, weight;
	Edge(int _f, int _t, int _w)
		: from(_f), to(_t), weight(_w) {}
};

using EdgeList = std::list<Edge>;

std::vector<EdgeList>
	transitive_closure_dfs(const std::vector<EdgeList> &edgelists);
void go_dfs(const int &now_vertax, const int &source_vertax,
		std::vector<bool> &check, EdgeList &transitive_edgelist,
		const std::vector<EdgeList> &edgelists);

int main()
{
	int N, M;

	std::cin >> N >> M;

	std::vector<EdgeList> edgelists(1 + N);


	for (int i = 0; i < M; i++)
	{
		int from, to;	
		std::cin >> from >> to;
		edgelists[from].emplace_back(from, to, 1);
	}

	std::vector<EdgeList> &&transitive_edgelists 
		= transitive_closure_dfs(edgelists);

	for (int idx = 1; idx <= N; idx++)
	{
		std::cout << "now vertax is " << idx << std::endl;
		for (auto &e: transitive_edgelists[idx])
			std::cout << e.from << "->" << e.to << " is reachable." << std::endl;
	}

}

std::vector<EdgeList>
	transitive_closure_dfs(const std::vector<EdgeList> &edgelists)
{
	int N = edgelists.size() - 1;
	std::vector<EdgeList> transitive_edgelists(1 + N);

	for (int idx = 1; idx <= N; idx++)
	{
		std::vector<bool> check(1 + N, false);
		go_dfs(idx, idx, check, transitive_edgelists[idx], edgelists);
	}

	return transitive_edgelists;
}

void go_dfs(const int &now_vertax, const int &source_vertax,
		std::vector<bool> &check, EdgeList &transitive_edgelist,
		const std::vector<EdgeList> &edgelists)
{
	check[now_vertax] = true;

	for (auto &e: edgelists[now_vertax])
	{
		if (check[e.to])
			continue;
		transitive_edgelist.emplace_back(source_vertax, e.to, e.weight);
		go_dfs(e.to, source_vertax, check, transitive_edgelist, edgelists);
	}
}
