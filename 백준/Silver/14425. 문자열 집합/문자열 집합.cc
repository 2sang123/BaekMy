#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	set<string> ss;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		ss.insert(s);
	}
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		string check;
		cin >> check;
		if (ss.find(check) != ss.end()) cnt++;
	}
	cout << cnt;
}
