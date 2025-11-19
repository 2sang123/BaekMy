#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> marr(n, 1);
    vector<int> sarr(n, 1);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            marr[i] = marr[i - 1] + 1;
        }
        else if (arr[i] < arr[i - 1])
        {
            sarr[i] = sarr[i - 1] + 1;
        }
        else
        {
            marr[i] = marr[i - 1] + 1;
            sarr[i] = sarr[i - 1] + 1;
        }
    }
    int out = 0;
    for (int i = 0; i < n; i++)
    {
        out = max({ out, sarr[i],marr[i] });
    }
    cout << out;
}
