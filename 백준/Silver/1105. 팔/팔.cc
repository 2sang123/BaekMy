#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int l, r;
int eight(int num)
{
	int cnt = 0;
	while (num > 0)
	{
		if (num % 10 == 8)
		{
			cnt++;
		}
		num /= 10;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> l >> r;
	int out = 1000;
	for (int i = l; i <= r; i++)
	{
		out = min(eight(i), out);
		if (out == 0) break;
	}
	cout << out;

}
