#include <iostream>
#include <cmath>
using namespace std;
int t;
long long int n;
bool primeTest(long long int num)
{
	if (num <= 1)
	{
		return false;
	}
	if (num <= 3)
	{
		return true; 
	}
	if (num % 2 == 0 || num % 3 == 0)
	{
		return false; 
	}


	int limit = static_cast<int>(sqrt(num));
	for (int i = 5; i <= limit; i += 6)
	{
		if (num % i == 0 || num % (i + 2) == 0)
		{
			return false; 
		}
	}
	return true;
}

long long int primeNext(long long int num)
{
	if (num < 2)
	{
		return 2;
	}

	while (!primeTest(num)) {
		num++;
	}
	return num;
}

int main() {
	cin >> t;
	while (t--)
	{
		long long int out = 0;
		cin >> n;
		out = primeNext(n);
		cout << out << endl;
	}
}
