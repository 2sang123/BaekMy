#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l;
    cin >> n >> l;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int cnt = 0;
    int cov = 0;
    for (int x : arr)
    {
        if (x > cov)
        {
            cnt++;
            cov = x + l - 1;
        }
    }
    cout << cnt;
}
