#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> arr;
    for (int i = 1; i <= n; i++)
    {
        arr.push_back(i);
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        int temp = arr[a - 1];
        arr[a - 1] = arr[b - 1];
        arr[b - 1] = temp;
    }

    for (auto out : arr)
    {
        cout << out << ' ';
    }
}
