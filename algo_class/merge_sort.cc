#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void mergeSort(vector<int> v)
{
}


int main()
{
	srand(time(0));
	vector<int> v(10);

	for (int i = 0; i < v.size(); i++)
	{
		v[i] = rand() % 1000;
	}

	cout << "Before sequence : ";
	for (auto e: v)
		cout << e << ' ';	
	cout << endl;

	mergeSort(v);

	cout << "After sequence : ";
	for (auto e: v)
		cout << e << ' ';	
	cout << endl;
}

