#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    string out;
    while (next_permutation(s.begin(), s.end()))
    {
        
        for (auto i = s.begin(); i < s.end(); i++)
        {
            out.push_back(*i);
        }
        break;
    }
    if (out.empty())
    {
        cout << 0;
    }
    else cout << out;
}
