#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <array>

using Vertax = char;
using EdgePiece = std::pair<int, int>;
using EdgeList = std::vector<EdgePiece>;
using Edge = std::tuple<int, int, int>;
using Node = std::pair<int, int>;

class Comparator
{
	public:
		bool operator() (const Edge &lhs, const Edge &rhs) const
		{
			return std::get<2>(lhs) > std::get<2>(rhs);
		}
};

enum class Category { Unseen, Fringe, Tree };

using EdgePQ = std::priority_queue<Edge, std::vector<Edge>, Comparator>;

void prim_with_ua(const std::vector<Vertax> &vertaxes, const std::vector<EdgeList> &edge_lists);
void prim_with_pq(const std::vector<Vertax> &vertaxes, const std::vector<EdgeList> &edge_lists);
void prim_optimal(const std::vector<Vertax> &vertaxes, const std::vector<EdgeList> &edge_lists);
void print_edge_lists(const std::vector<Vertax> &v, const std::vector<EdgeList> &els);
void print_fringe(const EdgePQ &epq);

int main()
{
	int N, M;
	std::cin >> N >> M;

	std::vector<Vertax> vertaxes(N + 1);
	std::vector<EdgeList> edge_lists(N + 1);


	for (int i = 1; i <= N; i++)
		vertaxes[i] = 'A' - 1 + i;

	for (int i = 0; i < M; i++)
	{
		int st, ed, cost;
		std::cin >> st >> ed >> cost;
		edge_lists[st].push_back(std::make_pair(ed, cost));
		edge_lists[ed].push_back(std::make_pair(st, cost));
	}
	// prim_with_pq(vertaxes, edge_lists);
	// prim_optimal(vertaxes, edge_lists);
	prim_with_ua(vertaxes, edge_lists);
	// print_edge_lists(vertaxes, edge_lists);
	// print_fringe(fringe_pq);

}

void prim_with_ua(const std::vector<Vertax> &vertaxes, const std::vector<EdgeList> &edge_lists)
{
	std::array<Edge, 27> fringe_ua;
	std::vector<Category> states(vertaxes.size());

	int sel_vertax = 1;
	states[sel_vertax] = Category::Tree;

	for (auto &e: edge_lists[sel_vertax])
	{
		fringe_ua[ua_cnt] = std::make_tuple(sel_vertax, e.first, e.second);
		states[e.first] = Category::Fringe;
		ua_cnt++;
	}

	while (ua_cnt > 0)
	{
		int now_min_idx = 1;

		for (now_min_idx = 1; now_min_idx < vertaxes.size(); now_min_idx++)
			if (states[now_min_idx] == Category::Fringe) break;
		
		for (int i = 1; i < vertaxes.size(); i++)
		{
			if (states[i] != Category::Fringe) continue;
			if (std::get<2>(fringe_ua[i]) < std::get<2>(fringe_ua[now_min_idx]))
				now_min_idx = i;
		}

		auto min_edge = fringe_ua[now_min_idx];
		states[now_min_idx] = Category::Tree;
		ua_cnt--;
		
		for (auto &e: edge_lists[now_min_idx])
		{
			if (states[e.first] == Category::Tree)
				continue;

			if (e.second < std::get<2>(fringe_ua[e.first]))
				
		}

		
		if (states[std::get<1>(min_edge)] != Category::Fringe)
			continue;
	}
}

void prim_with_pq(const std::vector<Vertax> &vertaxes, const std::vector<EdgeList> &edge_lists)
{
	std::vector<Node> tree;
	std::vector<Category> states(vertaxes.size());
	EdgePQ fringe_pq;
	int min_cost = 0;

	int sel_vertax = 1;

	states[sel_vertax] = Category::Tree;
	tree.push_back(std::make_pair(0, sel_vertax));

	for (auto e: edge_lists[sel_vertax])
	{
		states[e.first] = Category::Fringe;
		fringe_pq.push(std::make_tuple(sel_vertax, e.first, e.second));
	}

	while (!fringe_pq.empty())
	{
		auto edge = fringe_pq.top(); fringe_pq.pop();
		sel_vertax = std::get<1>(edge);

		if (states[sel_vertax] != Category::Fringe)
			continue;

		states[sel_vertax] = Category::Tree;
		tree.push_back(std::make_pair(std::get<0>(edge), sel_vertax));

		min_cost += std::get<2>(edge);

		for (auto e: edge_lists[sel_vertax])
		{
			if (states[e.first] == Category::Tree)
				continue;
			states[e.first] = Category::Fringe;
			fringe_pq.push(std::make_tuple(sel_vertax, e.first, e.second));
		}
	}

	std::cout << min_cost << std::endl;

	for (auto &node: tree)
		std::cout << vertaxes[node.second] << " ";
	std::cout << std::endl;
}

void prim_optimal(const std::vector<Vertax> &vertaxes, const std::vector<EdgeList> &edge_lists)
{
	std::vector<bool> chk(vertaxes.size());
	std::priority_queue< std::pair<int, int> > pq;

	int min_cost = 0;
	int now_idx = 1;

	chk[now_idx] = true;

	for (auto &e: edge_lists[now_idx])
		pq.push(std::make_pair(-e.second, e.first));

	std::cout << vertaxes[now_idx] << " ";

	while (!pq.empty())
	{
		auto ep = pq.top(); pq.pop();
		auto cost = -ep.first;
		auto now_idx = ep.second;

		if (chk[now_idx]) continue;

		chk[now_idx] = true;
		min_cost += cost;
		std::cout << vertaxes[now_idx] << " ";

		for (auto &e: edge_lists[now_idx])
			if (!chk[e.first]) pq.push(std::make_pair(-e.second, e.first));
	}

	std::cout << std::endl;
	std::cout << min_cost << std::endl;
}

void print_edge_lists(const std::vector<Vertax> &v, const std::vector<EdgeList> &els)
{
	int cnt = 0;
	for (auto &el: els)
	{
		if (cnt == 0)
		{
			cnt++;
			continue;
		}

		std::cout << "Vertax " << v[cnt] << " has..." << std::endl;
		for (auto &ep: el)
			std::cout << "\t" << v[cnt] << "->" << v[ep.first] << " / " << ep.second << std::endl;
		std::cout << std::endl;
		cnt++;
	}
}

void print_fringe(const EdgePQ &epq)
{
	auto copy_epq = epq;
	while (!copy_epq.empty())
	{
		auto e = copy_epq.top(); copy_epq.pop();
		std::cout << std::get<0>(e) << "->" << std::get<1>(e) << " / " << std::get<2>(e) << std::endl;
	}
}
