#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	pair<int, int> p1, p2, p3;
	cin >> p1.first >> p1.second >> p2.first
		>> p2.second >> p3.first >> p3.second;
	double d1 = (p2.first - p1.first) * (p3.second - p1.second);
	double d2 = (p2.second - p1.second) * (p3.first - p1.first);
	if (d1 == d2)
	{
		cout << "WHERE IS MY CHICKEN?";
	}
	else
	{
		cout << "WINNER WINNER CHICKEN DINNER!";
	}
}
