#include <iostream>
#include <string>

using namespace std;

string code;
int N;
int g_idx = 0;
bool is_invalid = false;

int parse_sum();

int parse_sum()
{
	if (is_invalid)
		return -1;

	int weight = 3;
	char end = ']', wrong = ')';
	if (code[g_idx] == '(')
	{
		weight = 2;
		end = ')';
		wrong = ']';
	}
	else if (code[g_idx] == ')' || code[g_idx] == ']')
	{
		is_invalid = true;
		return -1;
	}

	g_idx++;

	if (g_idx == N || code[g_idx] == wrong)
	{
		is_invalid = true;
		return -1;
	}

	if (code[g_idx] == end)
	{
		g_idx++;
		return weight;
	}

	int result = 0;

	while (g_idx < N)
	{
		if (code[g_idx] == '(' || code[g_idx] == '[')
			result += parse_sum();
		else if (code[g_idx] == end)
		{
			g_idx++;
			return weight * result;
		}
		else if (code[g_idx] == wrong)
		{
			is_invalid = true;
			return -1;
		}
	}

	is_invalid = true;
	return -1;
}

int main()
{
	cin >> code;
	N = code.length();

	int ans = 0;
	while (!is_invalid && g_idx < N)
	{
		ans += parse_sum();
	}

	if (is_invalid) ans = 0;

	cout << ans;
}

