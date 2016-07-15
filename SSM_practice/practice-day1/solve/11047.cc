#include <iostream>

using namespace std;

int a[10];

int main()
{
	int N, K; cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> a[i];

	int sum = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		sum += K / a[i]; 
		K %= a[i];
	}

	cout << sum;
}
