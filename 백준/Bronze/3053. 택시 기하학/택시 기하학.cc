#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const long double PI_ld = 3.141592653589793238L; 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	
	double uarea = n * n * PI_ld;
	double tarea = n * n * 2;
	cout << fixed;
	cout.precision(6);
	cout << uarea << '\n' << tarea;
}
