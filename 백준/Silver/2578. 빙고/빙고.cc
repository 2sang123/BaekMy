#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool bingo(vector<vector<bool>> &ch)
{
    int cnt = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (!ch[i][j]) break;
            else
            {
                if (j == 4) cnt++;
            }
        }
    }
    if (cnt >= 3) return true;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (!ch[j][i]) break;
            else
            {
                if (j == 4) cnt++;
            }
        }
    }
    if (cnt >= 3) return true;
    for (int i = 0; i < 5; i++)
    {
        if (!ch[i][i]) break;
        else if (i == 4 && ch[i][i]) cnt++;
    }
    if (cnt >= 3) return true;
    for (int i = 0; i < 5; i++)
    {
        if (!ch[i][4-i]) break;
        else if (i == 4) cnt++;
    }
    if (cnt >= 3) return true;

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> arr(5, vector<int>(5));
    vector<vector<bool>> check(5, vector<bool>(5, false));
    pair<int, int> pos[26];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> arr[i][j];
            pos[arr[i][j]] = { i, j };
        }
    }
    int b;
    int out = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> b;
            int r = pos[b].first;
            int c = pos[b].second;
            out++;
            check[r][c] = true;
            if (out >= 5)
            {
                if (bingo(check))
                {
                    cout << out;
                    return 0;
                }
            }
        }
    }
}
