#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	int paper;
	int board = 0;
	vector<int> arr;
	for (int i = 0; i < 6; i++)
	{
		cin >> paper;
		arr.push_back(paper);
	}
	board += arr[5];
	if (arr[4] > 0)
	{
		board += arr[4];
		arr[0] = max(0, arr[0] - arr[4] * 11);
	}

	if (arr[3] > 0)
	{
		board += arr[3];
		int emp2 = arr[3]*5;
		if (arr[1] >= emp2)
		{
			arr[1] -= emp2;
		}
		else
		{
			int emp = emp2 - arr[1];
			arr[1] = 0;
			arr[0] = max(0, arr[0] - emp * 4);
		}
	}

	if (arr[2] > 0)
	{
		board += arr[2] / 4;
		int remain = arr[2] % 4;
		if (remain > 0) board++;
		int emp2 = 0, emp1 = 0;
		if (remain == 1)
		{
			emp2 = 5, emp1 = 7;
		}
		else if (remain == 2)
		{
			emp2 = 3, emp1 = 6;
		}
		else if (remain == 3)
		{
			emp2 = 1, emp1 = 5;
		}
		if (remain > 0)
		{
			if (arr[1] >= emp2)
			{
				arr[1] -= emp2;
			}
			else
			{
				int e = emp2 - arr[1];
				arr[1] = 0;
				emp1 += e * 4;
			}
			arr[0] = max(0, arr[0] - emp1);
		}
	}
	if (arr[1] > 0)
	{
		board += arr[1] / 9;
		int emp = arr[1] % 9;
		if (emp > 0)
		{
			board++;
			arr[0] = max(0, arr[0] - (36 - emp * 4));
		}
	}
	if (arr[0] > 0)
	{
		board += arr[0] / 36;
		if (arr[0] % 36 != 0) board++;
	}
	cout << board;
}
