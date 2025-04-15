#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    
    priority_queue<pair<int,bool>,vector<pair<int,bool>>,greater<>> pq;
    while (n--)
    {
        int a;
        pair<int, bool> nums;
        cin >> a;
        if (a == 0)
        {
            if (pq.empty()) cout << 0 << '\n';
            else
            {
                if (pq.top().second) cout << pq.top().first << '\n';
                else cout << pq.top().first * -1 << '\n';
                pq.pop();
            }
        }
        else if (a > 0)
        {
            nums.first = a;
            nums.second = true;
            pq.push(nums);
        }
        else if (a < 0)
        {
            nums.first = a*-1;
            nums.second = false;
            pq.push(nums);
        }
    }
}
