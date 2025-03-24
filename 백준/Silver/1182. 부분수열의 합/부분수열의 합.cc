#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> s;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int cnt = 0;
    for (int bit = 0; bit < (1<<n); bit++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (bit & (1 << i))
            {
                sum += arr[i];
            }
        }
        if (sum == s) cnt++;
    }
    if (s == 0) cnt -= 1;
    cout << cnt;
}
