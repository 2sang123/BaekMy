#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int l;
	cin >> n >> l;
	vector<int> fruit(n);
	for (int i = 0; i < n; i++)
	{
		cin >> fruit[i];
	}
	sort(fruit.begin(), fruit.end());
	for (int i = 0; i < n; i++)
	{
		if (fruit[i] <= l)
		{
			l++;
		}
		else
		{
			cout << l;
			return 0;
		}
	}
	cout << l;
}
