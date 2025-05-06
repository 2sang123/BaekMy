#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;
	int out = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int a = s[i] - 'A';
		if (a > 14)
		{
			out += (a < 19) ? 8 : (a < 22) ? 9 : 10;
		}
		else
		{
			out += (a / 3) + 3;
		}
	}
	cout << out;
}
