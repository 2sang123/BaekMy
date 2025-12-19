#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

void next(vector<int>& arr)
{
    int s = arr.size();
    int num = s-2;
    while (num >= 0 && arr[num] <= arr[num + 1])
    {
        num--;
    }
    if (num >= 0)
    {
        int j = s - 1;
        while (arr[j] >= arr[num])
        {
            j--;
        }
        int temp = arr[num];
        arr[num] = arr[j];
        arr[j] = temp;
    }
    reverse(arr.begin() + num + 1, arr.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    vector<int> checks(n);
    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        checks[c] = i;
        c++;
    }
    if (checks == arr)
    {
        cout << -1;
    }
    else
    {
        next(arr);
        for (auto out : arr)
        {
            cout << out << ' ';
        }
    }

}
