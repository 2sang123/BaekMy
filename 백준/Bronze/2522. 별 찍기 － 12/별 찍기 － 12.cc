#include <iostream>
using namespace std;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int diss = n-1;
	bool re = false;
	for (int i = 0; i < 2*n -1; i++)
	{
		for (int j = 0; j < diss; j++)
		{
			cout << ' ';
		}
		for (int j = 0; j < n-diss; j++)
		{
			cout << '*';
		}
		cout << '\n';
		if (re)
			diss++;
		else
		{
			diss--;
		}
		if (diss == 0)
		{
			re = true;
		}
	}
}
