#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int n;

int bits = 0;

void addB(int a)
{
    bits |= (1 << a);
}
void removeB(int a)
{
    bits &= ~(1 << a);
}

void checkB(int a)
{
    if (bits & (1 << a))
    {
        cout << 1 << '\n';
    }
    else
    {
        cout << 0 << '\n';
    }
}

void toggleB(int a)
{
    if (bits & (1 << a))
    {
        bits &= ~(1 << a);
    }
    else
    {
        bits |= (1 << a);
    }
}

void allB()
{
    bits = (1 << 21) - 1;
}

void emptyB()
{
    bits = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    string s;
    while (n--)
    {
        cin >> s;
        if (s == "add")
        {
            int in;
            cin >> in;
            addB(in);
        }
        else if (s == "remove")
        {
            int in;
            cin >> in;
            removeB(in);
        }
        else if (s == "check")
        {
            int in;
            cin >> in;
            checkB(in);
        }
        else if (s == "toggle")
        {
            int in;
            cin >> in;
            toggleB(in);
        }
        else if (s == "all")
        {
            allB();
        }
        else if (s == "empty")
        {
            emptyB();
        }
    }
}
