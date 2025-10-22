#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> cow(10, -1);
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int c, p;
        cin >> c >> p;
        c= c-1;
        if (cow[c] == -1)
        {
            cow[c] = p;
        }
        else if(cow[c]!=-1&&cow[c]!=p)
        {
            cow[c] = p;
            cnt++;
        }
    }
    cout << cnt;
}
