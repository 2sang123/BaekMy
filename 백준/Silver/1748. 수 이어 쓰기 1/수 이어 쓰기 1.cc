#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    long long res = 0;
    long long p10 = 1;
    for (int i = 1; i <= 9; i++)
    {
        long long s = p10;
        long long mCount = 9 * p10;
        long long cnt = 0;
        if (n >= s)
        {
            cnt = n - s + 1;
            if (cnt > mCount) cnt = mCount;
        }
        res += cnt * i;
        p10 *= 10;
    }
    cout << res;
}
