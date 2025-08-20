#include <iostream>
using namespace std;
int a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b;
	if (a * (100 - b) >= 10000) 
	{
		cout << 0;
	}
	else 
	{
		cout << 1;
	}
}
