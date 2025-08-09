#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int sp = n-1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < sp; j++)
		{
			cout << ' ';
		}
		sp--;
		for (int j = 0; j <= i; j++)
		{
			cout << '*'<<' ';
		}
		cout << '\n';
	}
}
