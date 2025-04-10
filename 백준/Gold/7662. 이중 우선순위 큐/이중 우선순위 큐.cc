#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    int n;
    while (T--) 
    {
        char command;
        int k;
        multiset<int> dpque;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> command >> k;
            if (command == 'I')
            {
                dpque.insert(k);
            }
            else if (command == 'D')
            {
                if (!dpque.empty())
                {
                    if (k == 1)
                    {
                        dpque.erase(--dpque.end());     
                    }
                    else if (k == -1)
                    {
                        dpque.erase(dpque.begin()++);
                    }
                }
            }
        }

        if (!dpque.empty())
        {
            cout << *dpque.rbegin() << " " << *dpque.begin() << '\n';
        }
        else
        {
            cout << "EMPTY"<<'\n';
        }
    }
}
