#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool allTrue(bool oncheck[])
{
    for (int i = 0; i < 10; i++)
    {
        if (!oncheck[i]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int n;
    int i = 1;
    while (t--)
    {
        cin >> n;
        
        if (n == 0)
        {
            cout << "Case #" << i << ": INSOMNIA" << '\n';
        }
        else
        {
            bool on[10] = {false, };
            int mul = 1;
            while (!allTrue(on))
            {
                int num = n * mul;
                while (num > 0)
                {
                    on[num % 10] = true;
                    num /= 10;
                }
                if (allTrue(on)) break;
                mul++;
            }
            cout << "Case #" << i <<": " << n * mul << '\n';
        }
        i++;
    }

}
