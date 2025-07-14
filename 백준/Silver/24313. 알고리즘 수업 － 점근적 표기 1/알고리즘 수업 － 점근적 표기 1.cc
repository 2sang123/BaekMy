#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a1, a2, c, n;
	cin >> a1 >> a2 >> c >> n;

	if ((a1 * n + a2 <= c * n) && c >= a1)
	{
		cout << 1;
	}
	else cout << 0;
	
}
