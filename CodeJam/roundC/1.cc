#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)	
	{
		int N;
		cin >> N;

		vector< pair<char, int> > v(N);
		vector<double> m(N) , m_tmp(N); 
		vector< pair<double, int> > tmp(N);

		char party = 'A';
		unsigned int sum = 0;
		for (auto &e: v)
		{
			cin >> e.second;
			e.first = party++;
			sum += e.second;
			
		}

		// output
		printf("Case #%d: ", t);

		while (sum > 0)
		{
			for (int i = 0; i < N; i++)
			{
				m[i] = static_cast<double>(v[i].second) / sum;
				tmp[i] = make_pair(m[i], i);
			}

			sort(tmp.begin(), tmp.end());
			vector<int> evac = { (tmp.end() - 1)->second, (tmp.end() - 2)->second };

			for (int i = 0; i < N; i++)
			{
				if (evac[0] == i || evac[1] == i)
					m_tmp[i] = (static_cast<double>(v[i].second - 1)) / (sum - 2);
				else
					m_tmp[i] = static_cast<double>(v[i].second) / (sum - 2);

				if (m_tmp[i] > 0.5)
				{
					evac.pop_back();
					break;
				}
			}

			for (auto &e: evac)
			{
				cout << v[e].first; 
				v[e].second--;
				sum--;
			}
			cout << " ";
		}


		cout << endl;


	}
}
