#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <array>

struct Node
{
	int parent;
	int id;

	Node (int _p, int _i) : parent(_p), id(_i) {};
};

struct Edge
{
	int from, to, weight;

	bool operator< (const Edge &rhs) const
	{
		return this->weight < rhs.weight;
	}
};


class Comparator
{
	public:
		bool operator() (const Edge &lhs, const Edge &rhs) const
		{
			return lhs.weight > rhs.weight;
		}
};

enum class Category { Unseen, Fringe, Tree };

using Vertax = char;
using EdgeList = std::list<Edge>;
using EdgeUA = std::array<Edge, 27>;
using EdgePQ = std::priority_queue<Edge, std::vector<Edge>, Comparator>;

template<typename T, typename Callback>
T min(const T &lhs, const T &rhs, Callback callback)
{
	if (lhs < rhs)
		return lhs;
	else
	{
		callback(lhs, rhs);
		return rhs;
	}
}

template<typename Callback>
void prim_with_ua(const int &, const std::vector<EdgeList> &, Callback);
template<typename Callback>
void prim_with_pq(const int &, const std::vector<EdgeList> &, Callback);
template<typename Callback>
void prim_optimal(const int &, const std::vector<EdgeList> &, Callback);

void print_edge_lists(const std::vector<Vertax> &v, const std::vector<EdgeList> &els);
void print_fringe(const EdgePQ &epq);

int main()
{
	int N, M;
	std::cin >> N >> M;

	std::vector<Vertax> verticles(N + 1);
	std::vector<EdgeList> edge_lists(N + 1);


	for (int i = 1; i <= N; i++)
		verticles[i] = 'A' - 1 + i;

	for (int i = 0; i < M; i++)
	{
		int st, ed, cost;
		std::cin >> st >> ed >> cost;
		edge_lists[st].push_back(Edge{st, ed, cost});
		edge_lists[ed].push_back(Edge{ed, st, cost});
	}

	print_edge_lists(verticles, edge_lists);


	int min_cost;

	std::cout << ":: Prim Algorithm ::" << std::endl;
	
	std::cout << ":: >> with Unsorted Array ::" << std::endl;
	min_cost = 0;
	prim_with_ua(N, edge_lists, [&min_cost, &verticles] (const Edge &e, const EdgeUA &fringe, const std::vector<Category> &states)
			{
				for (int i = 1; i < states.size(); i++)
					std::cout << "    " << i;
				std::cout << std::endl;	

				for (int i = 1; i < states.size(); i++)
				{
					const auto &x = states[i];
					std::cout << "    ";
					switch (x)
					{
					case Category::Unseen:
						std::cout << 'U';
						break;
					case Category::Fringe:
						std::cout << 'F';
						break;
					case Category::Tree:
						std::cout << 'T';
						break;
					}
				}

				std::cout << std::endl;

				std::cout << verticles[e.from] << " -> " << verticles[e.to] << " / " << e.weight << std::endl;
				min_cost += e.weight;
			});
	std::cout << std::endl << min_cost << std::endl;

	std::cout << ":: >> with Priority Queue ::" << std::endl;
	min_cost = 0;
	prim_with_pq(N, edge_lists, [&min_cost, &verticles] (const Edge &e)
			{
				std::cout << verticles[e.from] << " -> " << verticles[e.to] << " / " << e.weight << std::endl;
				min_cost += e.weight;
			});
	std::cout << std::endl << min_cost << std::endl;

	std::cout << ":: >> with optimal ::" << std::endl;
	min_cost = 0;
	prim_optimal(N, edge_lists, [&min_cost, &verticles] (const Edge &e)
			{
				std::cout << verticles[e.to] << " ";
				min_cost += e.weight;
			});
	std::cout << std::endl << min_cost << std::endl;
	
	// print_fringe(fringe_pq);

}

template<typename Callback>
void prim_with_ua(const int &verticle_size, const std::vector<EdgeList> &edge_lists,
		Callback callback)
{
	EdgeUA fringe_ua{0, 0, 0};
	std::vector<Category> states(verticle_size + 1);

	int ua_cnt = 0;
	int sel_vertax = 1;
	states[sel_vertax] = Category::Tree;

	for (auto &e: edge_lists[sel_vertax])
	{
		fringe_ua[e.to] = e;
		states[e.to] = Category::Fringe;
		ua_cnt++;
	}

	callback(Edge{sel_vertax, sel_vertax, 0}, fringe_ua, states);

	while (ua_cnt > 0)
	{
		int min_idx = 1;

		for (min_idx = 1; min_idx <= verticle_size; min_idx++)
			if (states[min_idx] == Category::Fringe) break;

		
		for (int idx = min_idx + 1; idx <= verticle_size; idx++)
		{
			if (states[idx] == Category::Fringe &&
				fringe_ua[idx].weight < fringe_ua[min_idx].weight)
				min_idx = idx;
		}

		states[min_idx] = Category::Tree;
		ua_cnt--;
		
		for (auto &e: edge_lists[min_idx])
		{
			if (states[e.to] == Category::Tree)
				continue;
			else if (states[e.to] == Category::Unseen)
			{
				fringe_ua[e.to] = e;
				states[e.to] = Category::Fringe;
				ua_cnt++;
			}
			else
			{
				fringe_ua[e.to].weight = std::min(e.weight, fringe_ua[e.to].weight);
				if (e.weight == fringe_ua[e.to].weight)
					fringe_ua[e.to].from = e.from;
			}
		}

		callback(fringe_ua[min_idx], fringe_ua, states);
	}
}

template <typename Callback>
void prim_with_pq(const int &verticle_size, const std::vector<EdgeList> &edge_lists,
		Callback callback)
{
	std::vector<Category> states(verticle_size + 1);
	EdgePQ fringe_pq;

	int sel_vertax = 1;

	states[sel_vertax] = Category::Tree;

	for (auto &e: edge_lists[sel_vertax])
	{
		states[e.to] = Category::Fringe;
		fringe_pq.push(Edge{sel_vertax,  e.to,  e.weight});
	}

	callback(Edge{sel_vertax, sel_vertax, 0});

	while (!fringe_pq.empty())
	{
		auto edge = fringe_pq.top(); fringe_pq.pop();
		sel_vertax = edge.to;

		if (states[sel_vertax] != Category::Fringe)
			continue;

		states[sel_vertax] = Category::Tree;

		for (auto e: edge_lists[sel_vertax])
		{
			if (states[e.to] == Category::Tree)
				continue;
			states[e.to] = Category::Fringe;
			fringe_pq.push(Edge{sel_vertax,  e.to,  e.weight});
		}

		callback(edge);
	}
}

template <typename Callback>
void prim_optimal(const int &verticle_size, const std::vector<EdgeList> &edge_lists,
		Callback callback)
{
	std::vector<bool> chk(verticle_size + 1);
	std::priority_queue< std::pair<int, int> > pq;

	int min_cost = 0;
	int now_idx = 1;

	chk[now_idx] = true;

	for (auto &e: edge_lists[now_idx])
		pq.push(std::make_pair(-e.weight, e.to));

	callback(Edge{0, now_idx, 0});

	while (!pq.empty())
	{
		auto ep = pq.top(); pq.pop();
		auto cost = -ep.first;
		auto now_idx = ep.second;

		if (chk[now_idx]) continue;

		chk[now_idx] = true;

		for (auto &e: edge_lists[now_idx])
			if (!chk[e.to]) pq.push(std::make_pair(-e.weight, e.to));

		callback(Edge{0, now_idx, cost});
	}
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
			std::cout << "\t" << v[cnt] << "->" << v[ep.to] << " / " << ep.weight << std::endl;
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
		std::cout << e.from << "->" << e.to << " / " << e.weight << std::endl;
	}
}
