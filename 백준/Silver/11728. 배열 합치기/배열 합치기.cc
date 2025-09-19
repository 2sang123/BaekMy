#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> arr;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push(a);
    }
    for (int i = 0; i < m; i++)
    {
        int b;
        cin >> b;
        arr.push(b);
    }
    int s = arr.size();
    for (int i = 0; i < s; i++)
    {
        cout << arr.top() << ' ';
        arr.pop();
    }
}
