#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string zeros(int o)
{
    string s = to_string(o);
    if (o < 10)
    {
        return '0' + s;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c;
    int ta, tb, tc;
    int diss = 0;
    char s;
    cin >> a >> s >> b >> s >> c;
    cin >> ta >> s >> tb >> s >> tc;
    int oa, ob, oc;
    
    if (ta > a)
    {
        oc = tc - c;
        if (oc < 0)
        {
            diss++;
            oc = 60 + oc;
        }
        ob = tb - b - diss;
        diss = 0;
        if (ob < 0)
        {
            diss++;
            ob = 60 + ob;
        }

        oa = ta - a - diss;
    }
    else
    {
        oc = tc - c;
        if (oc < 0)
        {
            diss = 1;
            oc += 60;
        }
        else diss = 0;

        ob = tb - b - diss;
        if (ob < 0)
        {
            diss = 1;
            ob += 60;
        }
        else diss = 0;

        oa = (24 + ta) - a - diss;
    }
    if (oa == 24) oa = 0;
    
    
    cout << zeros(oa) << s << zeros(ob) << s << zeros(oc);

}
