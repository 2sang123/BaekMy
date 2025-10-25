#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> arr(n);
    int value = 0, from = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        from = (from + value) % n;
        value = arr[from];
        while (value > 0)
        {
            from = (from + 1) % n;
            value = arr[from];
        }
        arr[from] = num;
        value = num;
    }

    cout << n << '\n';
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
