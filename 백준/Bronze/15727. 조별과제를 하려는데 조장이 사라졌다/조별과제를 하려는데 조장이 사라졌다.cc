#include <iostream>
using namespace std;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int cnt = 0;
	while (n > 5)
	{
		n -= 5;
		cnt++;
	}
	if (n == 0)cout << cnt;
	else cout << cnt + 1;
}
