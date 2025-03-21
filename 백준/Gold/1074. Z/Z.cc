#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, r, c;

int cnt = 0;

void loops(int rs, int re, int cs, int ce, int s)
{
    if (s == 1)
    {
        return;
    }
    int midR = rs + (re - rs) / 2;
    int midC = cs + (ce - cs) / 2;
    int half = s / 2;

    if (r < midR && c < midC)
    {
        loops(rs, midR, cs, midC, half);
    }
    else if (r < midR && c >= midC)
    {
        cnt += half * half;
        loops(rs, midR, midC, ce, half);
    }
    else if (r >= midR && c < midC)
    {
        cnt += half * half * 2;
        loops(midR, re, cs, midC, half);
    }
    else if (r >= midR && c >= midC)
    {
        cnt += half * half * 3;
        loops(midR, re, midC, ce, half);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> r >> c;

    loops(0, pow(2,n), 0, pow(2,n), pow(2,n));
    cout << cnt;
}
