#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	int arr[4] = { 0, 0, 0, 0 };
	char c;
	for (int i = 0; i < 3; i++)
	{
		int cnt = 0;
		cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
		for (int j = 0; j < 4; j++)
		{
			if (arr[j] == 1) cnt++;
		}
		switch (cnt)
		{
		case 0:
			cout << 'D' << '\n';
			break;
		case 3:
			cout << 'A' << '\n';
			break;
		case 2:
			cout << 'B' << '\n';
			break;
		case 1:
			cout << 'C' << '\n';
			break;
		case 4:
			cout << 'E' << '\n';
			break;
		default:
			break;
		}
	}
}
