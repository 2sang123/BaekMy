#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    int a = 1;
    priority_queue<int,vector<int>, greater<int>> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a == 0)
        {
            if (arr.empty())
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << arr.top() << '\n';
                arr.pop();
            }   
        }
        else
        {
            arr.push(a);
        }
    }
}
