#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

int n, m;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_set<int> arr;
    unordered_set<int> brr;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int in = 0;
        cin >> in;
        arr.insert(in);
    }
    for (int i = 0; i < m; i++)
    {
        int in = 0;
        cin >> in;
        brr.insert(in);
    }
    int out = 0;
    for (int num : arr)
    {
        if (brr.find(num) == brr.end()) out++;
    }
    for (int num : brr)
    {
        if (arr.find(num) == arr.end()) out++;
    }

    cout << out;
}
