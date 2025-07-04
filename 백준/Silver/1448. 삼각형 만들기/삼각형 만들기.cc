#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n;

bool tri(int a, int b, int c)
{
    if (a + b > c && a + c > b && b + c > a)
    {
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end(), greater<>());
    for (int i = 0; i+2 < n; i++)
    {
        if (vec[i] < vec[i + 1] + vec[i + 2])
        {
            cout << vec[i] + vec[i + 1] + vec[i + 2];
            return 0;
        }
    }
    cout << -1;
}