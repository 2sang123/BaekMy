#include <iostream>
using namespace std;
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i % 2 != 0)
			{
				cout << ' ' << '*';
			}
			else
			{
				cout << '*' << ' ';
			}
		}
		cout << '\n';
	}
}
