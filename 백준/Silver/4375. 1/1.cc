#include <iostream>
using namespace std;
int n;
int main() {
	while (cin>>n)
	{
		long long int R = 1;
		int m = 1;
		while (R % n != 0)
		{
			R = ((R * 10) + 1)%n;
			m += 1;
		}
		cout << m<<endl;
	}
}
