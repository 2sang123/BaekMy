#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    double r, w, l;
    int i = 1;
    while (true)
    {
        cin >> r;
        if (r == 0) break;
        cin>> w >> l;

        if ((r*2)*(r*2) >= (w*w)+(l*l))
        {
            cout << "Pizza " << i << " fits on the table." << '\n';
        }
        else
        {
            cout << "Pizza " << i << " does not fit on the table." << '\n';
        }
        i++;
    }
}
