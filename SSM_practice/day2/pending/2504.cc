#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	string q;

	cin >> q;

	if (q[0] == ')' || q[0] == ']')
	{
		cout << 0;
		return;
	}

	stack<char> st;
	st.push(q[0]);

	int ans = 0;
	char now;

	for (int i = 1; i < q.length(); i++)
	{
		now = st.top();

		if (q[i] == ')')
		{
			if (now == '[')
			{
				ans = -1;
				break;
			}

			if (now == '(')
			{
				st.pop();
				st.push(2);
			}
			else
			{


			}
		}
		else if (q[i] == ']')
		{
			if (now == '(')
			{
				ans = -1;
				break;
			}
		}
		else
			st.push(q[i]);
	}

	if (ans == -1)
		ans = 0;
	else
	{
	}

	cout << ans;
}
