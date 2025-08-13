#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> alpha(26);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	string out;
	for (int i = 0; i < s.size(); i++)
	{
		alpha[s[i] - 'A']++;
	}
	char c;
	int h = 0;
	for (int i = 0; i < 26; i++)
	{
		if (alpha[i] % 2 == 1)
		{
			h++;
			c = 'A' + i;
		}
		if (h > 1 || (s.size()%2==0&&h>0))
		{
			cout << "I'm Sorry Hansoo";
			return 0;
		}
			
		if (alpha[i] > 0 && alpha[i]%2==0)
		{
			for (int j = 0; j < alpha[i]/2; j++)
			{
				out.push_back(i + 'A');
			}
		}
		else if (alpha[i] > 0 && alpha[i] % 2 == 1)
		{
			for (int j = 0; j < alpha[i]/2; j++)
			{
				out.push_back(i + 'A');
			}
		}
	}
	string cs = out;
	reverse(cs.begin(), cs.end());
	if (h > 0) out.push_back(c);
	cout << out << cs;
}
