#include <iostream>
#include <cstdio>
#include <vector>

inline int parent(int node) { return node / 2; }
inline int left_child(int node) { return 2 * node; }
inline int right_child(int node) { return 2 * node + 1; }

template <typename T>
void sift_down(std::vector<T> &v, int start, int end)
{
	int root = start;

	while (left_child(root) <= end)
	{
		int swap = root;

		if (v[swap] < v[left_child(root)])
			swap = left_child(root);

		if (right_child(root) <= end && v[swap] < v[right_child(root)])
			swap = right_child(root);

		if (root == swap)
			return;

		std::swap(v[root], v[swap]);
		root = swap;
	}
}

template <typename T>
void heapify(std::vector<T> &v)
{
	int count = v.size() - 1;
	int start = count;

	int root = parent(start);

	while (start > 0)
	{
		sift_down(v, start, count);
		start--;
	}
}

template <typename T>
void heap_sort(std::vector<T> &v)
{
	heapify(v);

	int end = v.size() - 1;
	
	while (end > 1)
	{
		std::swap(v[1], v[end]);
		end--;
		sift_down(v, 1, end);
	}
}

int main()
{
	std::vector<int> v{-1, 6, 3, 4, 2, 10, 9, 1, 7, 5, 8};

	heap_sort(v);

	for (auto &e: v)
		std::cout << e << ' ';
}
