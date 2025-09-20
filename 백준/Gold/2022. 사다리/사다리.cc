#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
double x, y, c;

double cal_c(double xx, double yy, double d)
{
    double h1 = sqrt(xx * xx - d * d);
    double h2 = sqrt(yy * yy - d * d);
    return (h1 * h2) / (h1 + h2);
}

double binary_d(double tx, double ty, double tc)
{
    double left = 0.0;
    double right = min(tx, ty);
    for (int i = 0; i < 100; i++)
    {
        double mid = (left + right) / 2.0;
        double nc = cal_c(tx, ty, mid);
        if (nc > tc) left = mid;
        else right = mid;
    }
    return (left + right) / 2.0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> x >> y >> c;
    cout.precision(3);
    cout <<fixed <<binary_d(x, y, c);
}
