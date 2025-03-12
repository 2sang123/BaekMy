#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
int a, b, c;
bool area(vector<vector<int>>& mat, int rs, int re, int cs, int ce)
{
    int start = mat[rs][cs];
    for (int i = rs; i < re; i++)
    {
        for (int j = cs; j < ce; j++)
        {
            if (mat[i][j] != start)
            {
                return false;
            }
        }
    }
    return true;
}

void divid(vector<vector<int>>& mat, int rs, int re, int cs, int ce)
{
    if (re <= rs || ce <= cs) return;

    if (area(mat,rs,re,cs,ce))
    {
        if (mat[rs][cs] == 1) a++;
        else if (mat[rs][cs] == 0) b++;
        else if (mat[rs][cs] == -1) c++;
        return;
    }

    int midR = rs + (re - rs) / 3;
    int midR2 = rs + (re - rs) / 3*2;

    int midC = cs + (ce - cs) / 3;
    int midC2 = cs + (ce - cs) / 3*2;

    divid(mat, rs, midR, cs, midC);

    divid(mat, midR, midR2, cs, midC);
    divid(mat, midR2, re, cs, midC);

    divid(mat, rs, midR, midC, midC2);
    divid(mat, rs, midR, midC2, ce);
    
    divid(mat, midR, midR2, midC, midC2);
    divid(mat, midR2, re, midC, midC2);
    
    divid(mat, midR, midR2, midC2, ce);
    divid(mat, midR2, re, midC2, ce);

}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    divid(mat, 0, n, 0, n);

    cout << c << '\n' << b << '\n' << a;
}
