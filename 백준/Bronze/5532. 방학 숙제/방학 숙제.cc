#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int l, a, b, c, d;
    cin >> l >> a >> b >> c >> d;
    int day = 0;
    if (a % c == 0&& b%d==0)
    {
        day = max(a / c, b / d);
    }
    else if (a % c != 0&&b%d!=0)
    {
        day = max(a / c + 1, b / d +1);
    }
    else if(a % c != 0 && b%d==0)
    {
        day = max(a / c + 1, b / d);
    }
    else if (a % c == 0 && b % d != 0)
    {
        day = max(a / c, b / d+1);
    }

    cout << l - day;
}
