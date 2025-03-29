#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int n;

int fruit(vector<int> &vec)
{
    int start = 0;
    int end = 0;
    int out = 0;
    unordered_map<int, int> cnts;
    while (end < vec.size())
    {
        cnts[vec[end]]++;

        while (cnts.size() > 2)
        {
            cnts[vec[start]]--;
            if (cnts[vec[start]] == 0)
            {
                cnts.erase(vec[start]);
            }
            start++;
        }
        out = max(out, end - start + 1);
        end++;
    }
    return out;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << fruit(arr);
}
