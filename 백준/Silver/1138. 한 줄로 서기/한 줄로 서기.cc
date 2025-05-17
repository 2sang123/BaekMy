#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;

void location(vector<int>& vec, int p, int num)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (vec[i]==0 && cnt==p)
		{
			vec[i] = num;
			return;
		}
		if (vec[i] == 0) cnt++;	
	}
	for (int i = 0; i < n; i++)
	{
		if (vec[i] == 0)
		{
			vec[i] = num;
			return;
		}
	}
	
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	vector<int> lines(n);
	int p;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		location(lines, p, i + 1);
		
	}
	for (auto a : lines)
	{
		cout << a << ' ';
	}

}
