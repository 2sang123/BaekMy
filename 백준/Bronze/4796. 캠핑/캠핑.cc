#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l=1, p=1, v=1;
    int c = 1;
    while (cin >> l >> p >> v)
    {
        if (l == 0 && p == 0 && v == 0) return 0;
        int cut = v / p;
        int num = v % p;
        if (num > l)
        {
            num = l;
        }
        int out = cut * l + num;
        cout << "Case " <<c<<": " <<out<<'\n';
        c++;
    }
}