#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> grid(10, vector<int>(10));
vector<pair<int, int>> arr;
bool checkShape(int rstart, int cstart, int h, int w, int type)
{
	vector<vector<int>> temp(10, vector<int>(10));
	vector<pair<int, int>> points;
	if (type == 1)
	{
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				temp[rstart + i][cstart + j] = 1;
			}
		}
		points = { {rstart, cstart},{rstart + h - 1, cstart},{rstart + h - 1, cstart + w - 1} };
	}
	else if (type == 2)
	{
		for (int i = 0; i < h; i++)
		{
			for (int j = w-1-i; j <= w-1; j++)
			{
				temp[rstart + i][cstart + j] = 1;
			}
		}
		points = { {rstart, cstart+w-1},{rstart + h - 1, cstart+w-1},{rstart + h - 1, cstart} };
	}
	else if (type == 3)
	{
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j <= h-1-i; j++)
			{
				temp[rstart + i][cstart + j] = 1;
			}
		}
		points = { {rstart, cstart},{rstart + h - 1, cstart},{rstart, cstart + w - 1} };
	}
	else if (type == 4)
	{
		for (int i = 0; i < h; i++)
		{
			for (int j = i; j <= w-1; j++)
			{
				temp[rstart + i][cstart + j] = 1;
			}
		}
		points = { {rstart, cstart},{rstart, cstart+w-1},{rstart + h - 1, cstart + w - 1} };
	}
	else if (type == 5)
	{
		int mid = w / 2;
		for (int i = 0; i < h; i++)
		{
			for (int j = mid-i; j <= mid+i; j++)
			{
				temp[rstart + i][cstart + j] = 1;
			}
		}
		points = { {rstart,cstart + mid},{rstart + h - 1, cstart},{rstart + h - 1,cstart + w - 1} };
	}
	else if (type == 6)
	{
		int mid = w / 2;
		for (int i = 0; i < h; i++)
		{
			for (int j = i; j <= w-i-1; j++)
			{
				temp[rstart + i][cstart + j] = 1;
			}
		}
		points = { {rstart, cstart}, {rstart, cstart + w - 1}, {rstart + h - 1, cstart + mid} };
	}
	else if (type == 7)
	{
		int mid = h / 2;
		for (int i = 0; i < h; i++)
		{
			int gap = abs(mid - i);
			for (int j = gap; j < w; j++)
			{
				temp[rstart + i][cstart + j] = 1;
			}
		}
		points = { {rstart, cstart+w-1},{rstart+mid,cstart},{rstart+h-1,cstart+w-1}};
	}
	else if (type == 8)
	{
		int mid = h / 2;
		for (int i = 0; i < h; i++) {
			int gap = abs(mid - i);
			for (int j = 0; j <= w - 1 - gap; j++) {
				temp[rstart + i][cstart + j] = 1;
			}
		}
		points = { {rstart, cstart},{rstart + mid,cstart + w - 1 },{rstart + h - 1,cstart} };
	}


	if (grid == temp)
	{
		arr = points;
		return true;
	}
	else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	int cnt = 0;
	int rb = 11, rs = -1, cb = 11, cs = -1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			char c;
			cin >> c;
			grid[i][j] = c - '0';
			if (grid[i][j] == 1)
			{
				cnt++;
				rb = min(rb, i);
				rs = max(rs, i);
				cb = min(j, cb);
				cs = max(j, cs);
			}
		}
	}
	if (cnt <= 2)
	{
		cout << 0;
		return 0;
	}
	pair<int, int> sp = { rs, cs };
	int h = rs - rb + 1;
	int w = cs - cb + 1;
	if (w == h)
	{
		if (checkShape(rb, cb, h, w, 1))
		{
			sort(arr.begin(), arr.end());
			for (auto p : arr) cout << p.first+1 << " " << p.second+1 << "\n";
			return 0;
		}
		if (checkShape(rb, cb, h, w, 2))
		{
			sort(arr.begin(), arr.end());
			for (auto p : arr) cout << p.first+1 << " " << p.second+1 << "\n";
			return 0;
		}
		if (checkShape(rb, cb, h, w, 3))
		{
			sort(arr.begin(), arr.end());
			for (auto p : arr) cout << p.first+1 << " " << p.second+1 << "\n";
			return 0;
		}
		if (checkShape(rb, cb, h, w, 4))
		{
			sort(arr.begin(), arr.end());
			for (auto p : arr) cout << p.first+1 << " " << p.second+1 << "\n";
			return 0;
		}
	}
	else if (w % 2 == 1 && h == (w + 1) / 2)
	{
		if (checkShape(rb, cb, h, w, 5))
		{
			sort(arr.begin(), arr.end());
			for (auto p : arr) cout << p.first+1 << " " << p.second+1 << "\n";
			return 0;
		}
		if (checkShape(rb, cb, h, w, 6))
		{
			sort(arr.begin(), arr.end());
			for (auto p : arr) cout << p.first+1 << " " << p.second+1 << "\n";
			return 0;
		}
	}
	else if (h % 2 == 1 && w == (h + 1) / 2)
	{
		if (checkShape(rb, cb, h, w, 7))
		{
			sort(arr.begin(), arr.end());
			for (auto p : arr) cout << p.first+1 << " " << p.second+1 << "\n";
			return 0;
		}
		if (checkShape(rb, cb, h, w, 8))
		{
			sort(arr.begin(), arr.end());
			for (auto p : arr) cout << p.first+1 << " " << p.second+1 << "\n";
			return 0;
		}
	}
	else
	{
		cout << 0;
		return 0;
	}
	cout << 0;
}
