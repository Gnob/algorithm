#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <array>

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

template <typename Callback>
void dijkstra_ua(const int &N, const std::vector<EdgeList> &edge_lists, Callback callback);
template <typename Callback>
void dijkstra_pq(const int &N, const std::vector<EdgeList> &edge_lists, Callback callback);
void print_edge_lists(const std::vector<Vertax> &v, const std::vector<EdgeList> &els);

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


	std::cout << ":: Dijkstra Algorithm ::" << std::endl;
	
	std::cout << ":: >> with Unsorted Array ::" << std::endl;
	dijkstra_ua(N, edge_lists, [&verticles] (const Edge &e)
			{
				std::cout << verticles[e.to] << " of distance from A is " << e.weight << std::endl;
			});

	std::cout << std::endl << ":: >> with Priority Queue ::" << std::endl;
	dijkstra_pq(N, edge_lists, [&verticles] (const Edge &e)
			{
				std::cout << verticles[e.to] << " of distance from A is " << e.weight << std::endl;
			});
}

template <typename Callback>
void dijkstra_ua(const int &N, const std::vector<EdgeList> &edge_lists, Callback callback)
{
	// Unsorted array of index means Edge of destination (to) 
	EdgeUA fringe_ua{0, 0, 0};
	int ua_cnt = 0;
	std::vector<Category> states(1 + N);
	std::vector<int> memo(1 + N, INT_MAX);

	int sel_vertax = 1;
	states[sel_vertax] = Category::Tree;
	memo[sel_vertax] = 0;

	for (auto &e: edge_lists[sel_vertax])
	{
		states[e.to] = Category::Fringe;
		fringe_ua[e.to] = e;
		ua_cnt++;
	}

	callback(Edge{sel_vertax, sel_vertax, 0});

	while (ua_cnt > 0)
	{
		int min_idx;
		
		for (min_idx = 1; min_idx <= N; min_idx++)
			if (states[min_idx] == Category::Fringe) break;

		for (int i = min_idx + 1; i <= N; i++)
		{
			if (states[i] == Category::Fringe
					&& fringe_ua[min_idx].weight > fringe_ua[i].weight)
				min_idx = i;
		}

		if (min_idx == N + 1) 
		{
			ua_cnt--;
			continue;
		}

		auto &now_edge = fringe_ua[min_idx];
		states[now_edge.to] = Category::Tree;
		memo[now_edge.to] = now_edge.weight;
		ua_cnt--;

		for (auto &e: edge_lists[now_edge.to])
		{
			if (states[e.to] == Category::Fringe
				&& fringe_ua[e.to].weight > memo[e.from] + e.weight)
			{
				fringe_ua[e.to].from = e.from;
				fringe_ua[e.to].to = e.to;
				fringe_ua[e.to].weight = memo[e.from] + e.weight;
			}
			else if (states[e.to] == Category::Unseen)
			{
				states[e.to] = Category::Fringe;
				fringe_ua[e.to].from = e.from;
				fringe_ua[e.to].to = e.to;
				fringe_ua[e.to].weight = memo[e.from] + e.weight;
				ua_cnt++;
			}
		}

		callback(now_edge);
	}
}

template <typename Callback>
void dijkstra_pq(const int &N, const std::vector<EdgeList> &edge_lists, Callback callback)
{
	EdgePQ fringe_pq;
	std::vector<Category> states(N + 1);
	std::vector<int> memo(N + 1, INT_MAX);

	int sel_vertax = 1;
	states[sel_vertax] = Category::Tree;
	memo[sel_vertax] = 0;

	for (auto &e: edge_lists[sel_vertax])
	{
		fringe_pq.push(e);
		states[e.to] = Category::Fringe;
	}

	callback(Edge{sel_vertax, sel_vertax, 0});

	while (!fringe_pq.empty())
	{
		auto now_edge = fringe_pq.top(); fringe_pq.pop();
		
		if (states[now_edge.to] == Category::Tree)
			continue;

		states[now_edge.to] = Category::Tree;
		memo[now_edge.to] = now_edge.weight;
		
		for (auto &e: edge_lists[now_edge.to])
		{
			if (states[e.to] != Category::Tree &&
					memo[e.to] > memo[e.from] + e.weight)
			{
				fringe_pq.push(Edge{e.from, e.to, memo[e.from] + e.weight});
				states[e.to] = Category::Fringe;
			}
		}

		callback(now_edge);
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
