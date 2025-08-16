#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s, target;
int cnt = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	getline(cin, s);
	getline(cin, target);
	size_t pos = s.find(target);
	while (pos != string::npos)
	{
		cnt++;
		pos = s.find(target, pos+target.size());
	}
	cout << cnt;
}
