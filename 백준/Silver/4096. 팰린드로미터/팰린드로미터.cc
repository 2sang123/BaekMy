#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

bool isPal(string s)
{
    int sizes = s.size();
    for (int i = 0; i < s.size()/2; i++)
    {
        if (s[i] != s[sizes - 1])
        {
            return false;
        }
        sizes--;
    }
    return true;
}

void addOne(string& s)
{
    int i = s.length() - 1;
    while (i >= 0)
    {
        if (s[i] == '9')
        {
            s[i] = '0';
            i--;
        }
        else
        {
            s[i]++;
            return;
        }
    }
    s.insert(0, "1");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while (cin >> s)
    {
        if (s.size()==1 && s[0] == '0') return 0;
        int cnt = 0;
        int t = stoi(s);
        while (!isPal(s))
        {
            cnt++;
            addOne(s);
        }
        cout << cnt << '\n';
    }
}
