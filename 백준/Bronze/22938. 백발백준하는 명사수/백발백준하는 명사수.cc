#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

pair<double, double> p1, p2;
double r1, r2;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> p1.first >> p1.second >> r1 >> p2.first >> p2.second >> r2;
	double dist = (p1.second - p2.second) * (p1.second - p2.second) + (p2.first - p1.first) * (p2.first - p1.first);
	dist = sqrt(dist);
	if (dist >= r1 + r2)
	{
		cout << "NO";
	}
	else
	{
		cout << "YES";
	}
}
