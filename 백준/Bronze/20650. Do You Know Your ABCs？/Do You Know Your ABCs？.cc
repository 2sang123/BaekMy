#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr(7);
    for (int i = 0; i < 7; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int a = arr.front();
    int abc = arr.back();
    int b = arr[1];
    int c = abc - (a + b);
    cout << a << ' ' << b << ' ' << c;
}
