#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;

int ties(vector<int>& vec)
{
	int sums = 0;
	int zeros = 0;
	vector<int> pvec, mvec;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] > 1)
		{
			pvec.push_back(vec[i]);
		}
		else if (vec[i] == 1)
		{
			sums++;
		}
		else if (vec[i] == 0)
		{
			zeros++;
		}
		else mvec.push_back(vec[i]);
	}

	sort(pvec.rbegin(), pvec.rend());
	for (int i = 0; i+1 < pvec.size(); i+=2)
	{
		sums += pvec[i] * pvec[i + 1];
	}
	if (pvec.size() % 2 == 1)
	{
		sums += pvec.back();
	}
	sort(mvec.begin(), mvec.end());
	for (int i = 0; i+1 < mvec.size(); i+=2)
	{
		sums += mvec[i] * mvec[i + 1];
	}
	if (mvec.size() % 2 == 1)
	{
		if(zeros==0)
			sums += mvec.back();
	}

	return sums;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	vector<int> vec(n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin>>vec[i];
	}
	sum = ties(vec);
	cout << sum;
}
