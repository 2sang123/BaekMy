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

    for (int i = 0; i <n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<int> res;
    int left = 0;
    int right = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            res.push_back(arr[right--]);
        }
        else
        {
            res.push_back(arr[left++]);
        }
    }
    int out = res[0];
    for (int i = 1; i < n; i++)
    {
        out += max(0, res[i] - res[i - 1]);
    }
    cout << out;
}
