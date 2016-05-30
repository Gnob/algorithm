#include<iostream>

using namespace std;

long long getValue(const string &str, bool isValue)
{
	long long result = 0;
	
	if (str == "black")
	{
		result = isValue ? 0 : 1;	
	}
	else if (str == "brown")
	{
		result = isValue ? 1 : 10;	
	}
	else if (str == "red")
	{
		result = isValue ? 2 : 100;	
	}
	else if (str == "orange")
	{
		result = isValue ? 3 : 1000;	
	}
	else if (str == "yellow")
	{
		result = isValue ? 4 : 10000;	
	}
	else if (str == "green")
	{
		result = isValue ? 5 : 100000;	
	}
	else if (str == "blue")
	{
		result = isValue ? 6 : 1000000;	
	}
	else if (str == "violet")
	{
		result = isValue ? 7 : 10000000;	
	}
	else if (str == "grey")
	{
		result = isValue ? 8 : 100000000;	
	}
	else if (str == "white")
	{
		result = isValue ? 9 : 1000000000;	
	}

	return result;
}

int main()
{
	string buf;
	long long result = 0;

	cin >> buf;
	result = getValue(buf, true) * 10;	
	cin >> buf;
	result += getValue(buf, true);	
	cin >> buf;
	result *= getValue(buf, false);	

	cout << result;
}

