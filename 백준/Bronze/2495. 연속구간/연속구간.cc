#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	for (int i = 0; i < 3; i++)
	{
		cin >> s;
		int cnt = 1;
		int out = 0;
		for (int j = 1; j < s.size(); j++)
		{
			char c = s[j];
			if (s[j - 1] == c)
			{
				cnt++;
			}
			else
			{
				out = max(cnt, out);
				cnt = 1;
			}
		}
		out = max(cnt, out);
		cout << out << '\n';
	}
}
