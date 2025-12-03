#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c;
    int tri=0, rtri=0, obtri =0, actri = 0;
    while (cin >> a >> b >> c)
    {
        int sum = a + b + c;
        int d = max({ a, b, c });
        int l = min({ a,b,c });
        int m = sum - (d + l);
        if (l+m <= d)
        {
            break;
        }
        else
        {
            if ((l* l) + (m * m) == d * d)
            {
                rtri++;
                tri++;
            }
            else if ((l * l) + (m * m) < d * d)
            {
                obtri++;
                tri++;
            }
            else if ((l * l) + (m * m) > d * d)
            {
                actri++;
                tri++;
            }
        }
    }
    cout << tri << ' ' << rtri << ' ' << actri << ' ' << obtri << '\n';
}
