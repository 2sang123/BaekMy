#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char v[5] = { 'a', 'e', 'i', 'o', 'u' };
bool check(string s)
{
    int con = 0;
    int vow = 0;
    bool vt = false;
    char back = ' ';
    for (int i = 0; i < s.size(); i++)
    {
        bool isvo = false;
        for (int j = 0; j < 5; j++)
        {
            if (s[i] == v[j])
            {
                vt = true;
                isvo = true;
                break;
            }
        }
        if (isvo)
        {
            vow++;
            con = 0;
        }
        else
        {
            con++;
            vow = 0;
        }

        if (i > 0 && s[i - 1] == s[i])
        {
            if (s[i] != 'e' && s[i] != 'o') return false;
        }

        if (con >= 3 || vow >= 3)
        {
            return false;
        }
    }
    return vt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while (cin >> s)
    {
        if (s == "end") return 0;
        if (check(s))
        {
            cout << "<" << s << "> is acceptable." << '\n';
        }
        else
        {
            cout << "<" << s << "> is not acceptable." << '\n';
        }
    }
}
