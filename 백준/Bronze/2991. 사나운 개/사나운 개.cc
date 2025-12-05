#include <iostream>
using namespace std;
int p, m, n;
int a, b, c, d;
int Adog(int t)
{
    if (t%(a + b) <= a && t % (a + b)!=0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Bdog(int t)
{
    if (t%(c + d) <= c && t % (c + d)!=0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> a >> b >> c >> d;
    cin >> p >> m >> n;
    int pc = Adog(p) + Bdog(p);
    int mc = Adog(m) + Bdog(m);
    int nc = Adog(n) + Bdog(n);
    cout << pc << endl << mc << endl << nc;
}
