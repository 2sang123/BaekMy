#include <iostream>
#include <vector>
#include <string>
using namespace std;

string s;
bool b = false;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> s)
    {
        if (s == "0") break;
        int right = 0;
        int left = s.size() - 1;
        if (s.size() == 1) b = true;
        while (right < left)
        {
            if (s[right] == s[left])
            {
                right++;
                left--;
            }
            else
            {
                b = false;
                break;
            }
            b = true;
        }
        if (b) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
