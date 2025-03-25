#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> dp1(50), dp2(50);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int in = 0;
    dp1[0] = 1;
    dp1[1] = 0;
    dp1[2] = 1;

    dp2[0] = 0;
    dp2[1] = 1;
    dp2[2] = 1;

    while (n--)
    {
        cin >> in;
        for (int i = 3; i <= in; i++)
        {
            dp1[i] = dp1[i - 1] + dp1[i - 2];
            dp2[i] = dp2[i - 1] + dp2[i - 2];
        }
        cout << dp1[in] << ' ' << dp2[in] << '\n';
    }
}
