#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    while (cin>>a>>b)
    {
        int cnt = 0;
        if (a == 0 && b == 0) return 0;
        int ca = a;
        int cb = b;
        int c = 0;
        while (ca > 0 || cb > 0)
        {
            if (ca % 10 + cb % 10 + c >= 10)
            {
                cnt++;
                c = 1;
            }
            else c = 0;
            ca /= 10;
            cb /= 10;
        }
        cout << cnt << '\n';
    }
}
