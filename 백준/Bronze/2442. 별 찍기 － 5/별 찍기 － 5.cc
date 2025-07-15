#include <iostream>
using namespace std;
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = n-1; j >= i; j--)
		{
			cout << ' ';
		}
		for (int k = 0; k < (2*i)-1; k++)
		{
			cout << '*';
		}
		cout << '\n';
	}
	
}
