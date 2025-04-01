#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;

void star(vector<string> &str, int x, int y, int size)
{
    if (size == 1) return;
    int cut = size / 3;
    for (int i = x+cut; i < x+2*cut; i++)
    {
        for (int j = y+cut; j < y+2 *cut; j++)
        {
            str[i][j] = ' ';
        }
    }
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1) continue;
            star(str, x + i * cut, y+j*cut,cut);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        s += '*';
    }

    vector<string> stars(n, s);
    star(stars,0,0,n);
    for (auto a : stars)
    {
        cout << a << '\n';
    }
}

