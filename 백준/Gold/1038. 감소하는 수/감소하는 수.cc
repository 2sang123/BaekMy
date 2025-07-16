#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define ll long long

int n;
ll out = -1;
int cnt = 0;
void back(ll num, int size)
{
	if (size == 0)
	{
		if (cnt == n)
		{
			out = num;
		}
		cnt++;
		return;
	}
	int last = num % 10;
	if (num == 0) last = 10;
	for (int i = 0; i < last; i++)
	{
		ll nextNum = (num * 10) + i;
		if (num == 0 && i == 0) continue;
		back(nextNum, size - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i <= 10; i++)
	{
		back(0, i);
	}
	cout << out;
	
}
