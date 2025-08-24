#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int r, c, zr, zc;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c >> zr >> zc;
	vector<string> vec(r);
	for (int i = 0; i < r; i++)
	{
		cin >> vec[i];
	}

	for (int i = 0; i < r; i++)
	{
		for (int l = 0; l < zr; l++)
		{
			for (int j = 0; j < c; j++)
			{
				for (int k = 0; k < zc; k++)
				{
					cout << vec[i][j];
				}
			}
			cout << '\n';
		}
	}
}
