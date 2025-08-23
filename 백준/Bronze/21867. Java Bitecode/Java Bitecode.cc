#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s = "";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char c;
		cin >> c;
		if ((c != 'A' && c != 'J') && c != 'V')
		{
			s.push_back(c);
		}
	}
	if (s.size() > 0)
	{
		cout << s;
	}
	else
	{
		cout << "nojava";
	}
}
