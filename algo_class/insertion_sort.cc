#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int shiftVacRec(vector<int> &v, int vaccant, int x)
{
	int xLoc;
	if (vaccant == 0)
		xLoc = vaccant;
	else if (v[vaccant - 1] <= x)
		xLoc = vaccant;
	else
	{
		v[vaccant] = v[vaccant - 1];
		xLoc = shiftVacRec(v, vaccant - 1, x);
	}

	return xLoc;
}

void insertionSort(vector<int> &v)
{
	for (int xindex = 1; xindex < v.size(); xindex++)
	{
		int x = v[xindex];
		int xLoc = shiftVacRec(v, xindex, x);
		v[xLoc] = x;
	}
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

	insertionSort(v);

	cout << "After sequence : ";
	for (auto e: v)
		cout << e << ' ';	
	cout << endl;
}

