#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int cost, s;
    cin >> n >> cost >> s;
    bool clear = false;
    for (int i = 0; i < n; i++)
    {
        int c, p;
        cin >> c >> p;
        if (c <= cost && p>s)
        {
            clear = true;
        }
    }
    if (clear) cout << "YES";
    else cout << "NO";
}
