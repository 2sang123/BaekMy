#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	set<int> s;
	for (int i = 1; i <= 10000; i++)
	{
		int in = 0;
		if (i < 10)
		{
			in = i + i;
			s.insert(in);
		}
		else if (i >= 10 && i < 100)
		{
			in = i + i / 10 + i % 10;
			s.insert(in);
		}
		else if (i >= 100 && i < 1000)
		{
			in = i + (i / 100) + ((i / 10) % 10) + i % 10;
			s.insert(in);
		}
		else if (i >= 1000 && i < 10000)
		{
			in = i + (i / 1000) + (i / 100) % 10 + (i / 10) % 10 + i % 10;
			s.insert(in);
		}
	}
	for (int i = 1; i < 10000; i++)
	{
		if (s.find(i) == s.end()) cout << i << '\n';
	}
}
