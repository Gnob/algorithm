#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N;
	int kbs1_idx, kbs2_idx;

	cin >> N;
	vector<string> v;

	for (int i = 0; i < N; i++)
	{
		char buf[11];
		scanf("%s", buf);	
		string str = string(buf);
		v.push_back(str);

		if (str == "KBS1")
			kbs1_idx = i;
		else if (str == "KBS2")
			kbs2_idx = i;
	}

		
}
