#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    set<int> s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        s.insert(a);
    }
    for (auto out : s)
    {
        cout << out << ' ';
    }
}
