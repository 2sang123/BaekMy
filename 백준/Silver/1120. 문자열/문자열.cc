#include <iostream>
#include <string>
using namespace std;

string s1, s2;
int counter(string s, string t)
{
    int r = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != t[i]) r++;
    }
    return r;
}
int strCounter(string s, string t)
{
    int mdiff = t.size();
    for (int i = 0; i <= s.size()-t.size() ; i++)
    {
        int d = 0;
        for (int j = 0; j < t.size(); j++)
        {
            if (s[i+j] != t[j]) d++;
        }
        mdiff = min(d, mdiff);
    }
    return mdiff;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s1 >> s2;
    int ans = 0;
    if (s1.size() == s2.size()) cout << counter(s1, s2);
    else if(s1.size()>s2.size())
    {
        ans = strCounter(s1, s2);
        cout << ans;
    }
    else if (s2.size() > s1.size())
    {
        ans = strCounter(s2, s1);
        cout << ans;
    }
}