#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int change = n;
    vector<int> arr;
    while (change > 0)
    {
        arr.push_back(change%9);
        change /=9;
    }
    reverse(arr.begin(), arr.end());
    for (auto out : arr)
    {
        cout << out;
    }
}
