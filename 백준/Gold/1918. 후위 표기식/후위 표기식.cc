#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    stack<char> backs;
    string outs;
    char keep = '0';
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A'&&s[i]<='Z')
        {
            outs.push_back(s[i]);
        }
        else if (s[i]=='(')
        {
            backs.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (backs.size())
            {
                if (backs.top() == '(') break;
                outs += backs.top();
                backs.pop();
            }
            backs.pop();
        }
        else if (s[i] == '*' || s[i] == '/')
        {
            while (backs.size()&&(backs.top()=='*'||backs.top()=='/'))
            {
                outs += backs.top();
                backs.pop();
            }
            backs.push(s[i]);
        }
        else if (s[i] == '+' || s[i] == '-')
        {
            while (backs.size())
            {
                if (backs.top() == '(') break;
                outs += backs.top();
                backs.pop();
            }
            backs.push(s[i]);
        }
    }
    while (!backs.empty())
    {
        outs += backs.top();
        backs.pop();
    }
    cout << outs;

}
