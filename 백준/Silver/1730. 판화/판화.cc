#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
string s;
vector<vector<char>> board;

void draw(vector<vector<char>> &board)
{
	int x = 0;
	int y = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int nx = x, ny = y;
		if (s[i] == 'D') ny++;
		else if (s[i] == 'U') ny--;
		else if (s[i] == 'R') nx++;
		else if (s[i] == 'L') nx--;

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (s[i] == 'D' || s[i] == 'U') {
			if (board[y][x] == '.') board[y][x] = '|';
			else if (board[y][x] == '-') board[y][x] = '+';
		}
		else {
			if (board[y][x] == '.') board[y][x] = '-';
			else if (board[y][x] == '|') board[y][x] = '+';
		}

		if (s[i] == 'D' || s[i] == 'U') {
			if (board[ny][nx] == '.') board[ny][nx] = '|';
			else if (board[ny][nx] == '-') board[ny][nx] = '+';
		}
		else {
			if (board[ny][nx] == '.') board[ny][nx] = '-';
			else if (board[ny][nx] == '|') board[ny][nx] = '+';
		}

		x = nx;
		y = ny;
	}
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> s;
	board.assign(n, vector<char>(n, '.'));
	draw(board);
	
	for (auto a : board)
	{
		for (auto b : a)
		{
			cout << b;
		}
		cout << '\n';
	}
}
