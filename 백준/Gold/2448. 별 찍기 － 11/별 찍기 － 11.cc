#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

void stars(vector<string>& str, int x, int y, int size)
{
    if (size == 3)
    {
        str[x][y] = '*';
        str[x+1][y-1] = '*';
        str[x+1][y+1] = '*';
        str[x+2][y-2] = '*';
        str[x+2][y-1] = '*';
        str[x+2][y] = '*';
        str[x+2][y+1] = '*';
        str[x+2][y+2] = '*';
        return;
    }
    
    int newS = size / 2;
    stars(str, x, y, newS);
    stars(str, x + newS, y - newS, newS);
    stars(str, x + newS, y + newS, newS);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    
    vector<string> tris;
    string s;
    s.assign((n * 2)-1, ' ');
    tris.assign(n, s);
    stars(tris, 0, n-1, n);

    for (const auto &a : tris)
    {
        cout << a << '\n';
    }
}
