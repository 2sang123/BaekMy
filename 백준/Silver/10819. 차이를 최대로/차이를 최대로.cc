#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int absm(int a, int b)
{
    return abs(a - b);
}

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
    int out = 0;
    sort(arr.begin(), arr.end());
    do {
        int sum = 0;
        for (auto it = arr.begin(); it != arr.end()-1; it++)
        {
            sum += absm(*it, *(it + 1));
        }
        out = max(sum, out);
    } while (next_permutation(arr.begin(), arr.end()));
    cout << out;
}
