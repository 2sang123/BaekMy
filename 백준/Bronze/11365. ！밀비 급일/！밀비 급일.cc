#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while (getline(cin, s))
    {
        if (s.compare("END")==0)
        {
            break;
        }
        reverse(s.begin(), s.end());
        cout << s << '\n';
    }
}
