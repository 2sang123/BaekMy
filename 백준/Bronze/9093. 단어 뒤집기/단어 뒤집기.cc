#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	string s;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		getline(cin, s);
		int cut = 0;
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == ' ')
			{
				reverse(s.begin()+cut, s.begin()+j);
				cut = j + 1;
			}
			else if (j + 1 == s.size())
			{
				reverse(s.begin() + cut, s.begin() + j+1);
			}
		}
		cout << s << '\n';
	}
}
