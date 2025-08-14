#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a=1, b=1;
	while (cin>>a>>b)
	{
		if (a == 0 && b == 0) return 0;
		if (a > b)
		{
			cout << "Yes" << '\n';
		}
		else if(a<=b)
		{
			cout << "No" << '\n';
		}
		
	}

}
