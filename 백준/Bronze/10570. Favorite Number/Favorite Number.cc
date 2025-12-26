#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    
    while (t--)
    {
        vector<int> arr(1001);
        int v;
        cin >> v;
        int target=0;
        int out = 1001;
        for (int i = 0; i < v; i++)
        {
            int s;
            cin >> s;
            arr[s - 1]++;
        }
        for (int i = 1; i <= 1001; i++)
        {
            if (arr[i-1] > target)
            {
                target = arr[i-1];
                out = i;
            }
            else if (arr[i-1] == target)
            {
                out = min(out, i);
            }
        }
        cout << out << '\n';
    }
}
