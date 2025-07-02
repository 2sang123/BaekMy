#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    priority_queue<int> lq;
    priority_queue<int, vector<int>, greater<int>> hq;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (lq.empty() || a <= lq.top())
        {
            lq.push(a);
        }
        else
        {
            hq.push(a);
        }

        if (lq.size() > hq.size() + 1)
        {
            hq.push(lq.top());
            lq.pop();
        }
        else if (hq.size() > lq.size())
        {
            lq.push(hq.top());
            hq.pop();
        }
        cout << lq.top() << '\n';
    }
}