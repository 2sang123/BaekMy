#include <iostream>
#include <string>
#include<vector>
using namespace std;
string s;
vector<int> abc(26, -1);
int main() {
	
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];
		if (c >= 'a' && c <= 'z')
		{
			if (abc[c - 'a'] == -1)
			{
				abc[c - 'a'] = i;
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << abc[i]<< " ";
	}
}
