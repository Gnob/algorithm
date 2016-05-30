#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>

using namespace std;

set<char> expChar;

string buf, exp;
int cnt;

bool cmp(const char &a, const char &b)
{
	int isExpA, isExpB = expChar.count(b);	

	if (isExpB == 1)
	{
		isExpA = expChar.count(a);	

		if (isExpA == 1)
		{
			return a < b;
		}

		return true;
	}
	return false;
}

int main()
{
	cin >> buf >> exp;
	map<char, int> expMap;

	sort(exp.begin(), exp.end());

	for (int i = 0; i < exp.size(); i++)
	{
		expChar.insert(exp[i]);
		expMap[exp[i]] = i + 1;
	}

	stable_sort(buf.begin(), buf.end(), cmp);

	int first = 0;
	int nextIdx;

	for (int j = buf.size() - 1; j >= 0; j--)
	{
		if (expChar.count(buf[j]) != 0)
		{
			if (expMap[buf[j]] == 1)
			{
				first = buf.find(buf[j]);
				break;
			}

			nextIdx = buf.rfind(exp[expMap[buf[j]] - 2], j);
			if (nextIdx == -1)
			{
				first = j;
				break;
			}
		}
		else {
			first = j + 1;
			break;
		}
	}

	cout << first << endl;

	if (first == 0)
	{
		cout << "FRULA";
		return 0;
	}

	if (first != buf.size())
		buf.erase(buf.begin() + first, buf.end());

	cout << buf;
}


