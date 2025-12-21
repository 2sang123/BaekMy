#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int n;
    while (t--)
    {
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> brr(n);
        int num = 1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == num)
            {
                brr[i] = num + 1;
                num++;
            }
            else
            {
                brr[i] = num;
            }
            num++;
        }
        cout << brr[n - 1] << '\n';
    }
}
