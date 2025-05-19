#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	while (s.compare("."))
	{
		getline(cin, s, '.');
		bool balance = true;
		vector<char> bal;
		int r = 0, l = 0, rr = 0, ll = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(' || s[i] == '[')
			{
				if (s[i] == '(') r++;
				else if (s[i] == '[') rr++;
				bal.push_back(s[i]);
			}
			else if (s[i] == ')')
			{
				l++;
				if (!bal.empty() && bal.back() == '(') bal.pop_back();
				else
				{
					balance = false;
					break;
				}
			}
			else if (s[i] == ']')
			{
				ll++;
				if (!bal.empty() && bal.back() == '[') bal.pop_back();
				else
				{
					balance = false;
					break;
				}
			}
		}
		if (s.size() == 1) break;
		if (balance&&r==l&&rr==ll) cout << "yes\n";
		else cout << "no\n";
	}
	
}
