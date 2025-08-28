#include <iostream>
using namespace std;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		sum += b % a;
	}
	cout << sum;
}
