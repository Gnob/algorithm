#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

string oper = "+-*/";
stack<int> calc;
vector<char> exp;

int isToken(char ch)
{
	for (int i = 0; i < oper.size(); i++)
	{
		if (oper[i] == c) return i;
	}
	return -1;
}

int solve(int idxA, int idxB, int oper)
{
	int _a, _b;
	int oper;
	oper = isToken(idxA);
	if (oper > -1) _a = solve(idxA - 2, idxA - 1);
	oper = isToken(idxB);
	if (oper > -1) _b = solve(idxB - 2, idxB - 1);

	switch(oper)
	{
		case '+':
			return _a + _b;
		case '-':
			return _a - _b;
		case '*':
			return _a * _b;
		case '/':
			return _a / _b;
		default:
			break;
	}

	
}

int main()
{
	char buf;

	while (scanf("%c", &buf))
	{
		if (buf == ' ') continue;
		else if (buf == '\n') break;
		exp.push_back(buf);
	}

	reverse(exp.begin(), exp.end());

	int result = 0;
	
	for (int i = 0; i < exp.size(); i++)
	{
		switch(exp[i])
		{
			case '+':
				break;
			case '-':
				break;
			case '*':
				i++;
				if (exp[i] == 'X') i++;
				result /= exp[i];
				break;
			case '/':
				i++;
				result *= exp[i];
				break;
			default:
				break;
		}

	}


}
