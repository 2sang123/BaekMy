#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector < vector<int>> board(9, vector<int>(9, 0));

bool isValid(int row, int col, int num) {
	for (int i = 0; i < 9; ++i) {
		if (board[row][i] == num) return false;
	}
	for (int i = 0; i < 9; ++i) {
		if (board[i][col] == num) return false;
	}
	int startRow = (row / 3) * 3;
	int startCol = (col / 3) * 3;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (board[startRow + i][startCol + j] == num) return false;
		}
	}
	return true;
}

bool solveSudoku() {
	for (int row = 0; row < 9; ++row) {
		for (int col = 0; col < 9; ++col) {
			if (board[row][col] == 0) {
				for (int num = 1; num <= 9; ++num) {
					if (isValid(row, col, num)) {
						board[row][col] = num;
						if (solveSudoku()) return true;
						board[row][col] = 0;
					}
				}
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			char c;
			cin >> c;
			board[i][j] = c - '0';
		}
	}
	if (solveSudoku()) {
		for (const auto& row : board) {
			for (int num : row) {
				cout << num;
			}
			cout << '\n';
		}
	}
}
