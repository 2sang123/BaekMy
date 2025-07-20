#include <iostream>
#include <string>
using namespace std;
string s;

int wordCheck(string s)
{
	int cnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'c')
		{
			if (i + 1 < s.size())
			{
				if (s[i + 1] == '-' || s[i + 1] == '=')
				{
					i++;
					cnt++;
				}
				else
				{
					cnt++;
				}
			}
			else cnt++;
		}
		else if (s[i] == 'd')
		{
			if (i + 1 < s.size())
			{
				if (s[i + 1] == '-')
				{
					i++;
					cnt++;
				}
				else if (i + 2 < s.size())
				{
					if (s[i + 1] == 'z' && s[i + 2] == '=')
					{
						i += 2;
						cnt++;
					}
					else cnt++;
				}
				else cnt++;
			}
			else cnt++;
		}
		else if (s[i] == 'l')
		{
			if (i + 1 < s.size())
			{
				if (s[i + 1] == 'j')
				{
					i++;
					cnt++;
				}
				else cnt++;
			}
			else cnt++;
		}
		else if (s[i] == 'n')
		{
			if (i + 1 < s.size())
			{
				if (s[i + 1] == 'j')
				{
					i++;
					cnt++;
				}
				else cnt++;
			}
			else cnt++;
		}
		else if (s[i] == 's')
		{
			if (i + 1 < s.size())
			{
				if (s[i + 1] == '=')
				{
					i++;
					cnt++;
				}
				else cnt++;
			}
			else cnt++;
		}
		else if (s[i] == 'z')
		{
			if (i + 1 < s.size())
			{
				if (s[i + 1] == '=')
				{
					i++;
					cnt++;
				}
				else cnt++;
			}
			else cnt++;
		}
		else cnt++;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	cout << wordCheck(s);
}
