#include <iostream>
using namespace std;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int diss = 1;
	bool re = false;
	for (int i = 0; i < 2 * n - 1; i++)
	{
		for (int j = 0; j < diss; j++)
		{
			cout << '*';
		}
		cout << '\n';
		if (!re)
			diss++;
		else
		{
			diss--;
		}
		if (diss == n)
		{
			re = true;
		}
	}
}
