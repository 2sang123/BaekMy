#include <iostream>
#include <vector>
using namespace std;

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	vector<int> diff(n + 1, 0);

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		diff[x - 1] += 1;
		diff[y - 1] -= 1;
	}

	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += diff[i];
		if (sum == 0) cnt++;
	}
	cout << cnt;
}
