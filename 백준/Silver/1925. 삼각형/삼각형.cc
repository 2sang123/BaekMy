#include <iostream>
#include <math.h>
#include <algorithm>
#include <cmath>
using namespace std;

double dist(pair<int, int> A, pair<int, int> B)
{
    return sqrt((B.first - A.first) * (B.first - A.first) + 
        (B.second - A.second) * (B.second - A.second));
}

double gradi(pair<int, int> A, pair<int, int> B)
{
    if (A.first == B.first) return 0;
    return abs(1.0 * (B.second - A.second) / (B.first - A.first));
}

int angles(double T, double a, double b)
{
    double lhs = T * T;
    double rhs = a * a + b * b;
    if (lhs > rhs) return 1;
    else if (fabs(lhs - rhs) < 1e-9) return 0;
    else return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pair<int, int> a, b, c;
    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;

    double ab = gradi(a, b);
    double ac = gradi(a, c);
    double bc = gradi(b, c);

    double abdist = dist(a, b);
    double acdist = dist(a, c);
    double bcdist = dist(b, c);

    double bigDist = max({ abdist, acdist, bcdist });

    if (ab == ac && ab == bc)
    {
        cout << 'X';
    }
    else if (abdist == acdist && abdist == bcdist)
    {
        cout << "JungTriangle";
    }
    else if ((abdist == acdist) || (abdist == bcdist) || (acdist == bcdist))
    {
        int angle = -2;
        if (bigDist == abdist) angle = angles(abdist, bcdist, acdist);
        else if (bigDist == acdist) angle = angles(acdist, bcdist, abdist);
        else if (bigDist == bcdist) angle = angles(bcdist, acdist, abdist);

        if (angle == 1) cout << "Dunkak2Triangle";
        else if (angle == 0) cout << "Jikkak2Triangle";
        else if (angle == -1)cout << "Yeahkak2Triangle";
    }
    else if (abdist != acdist && abdist != bcdist && acdist != bcdist)
    {
        int angle = -2;
        if (bigDist == abdist) angle = angles(abdist, bcdist, acdist);
        else if (bigDist == acdist) angle = angles(acdist, bcdist, abdist);
        else if (bigDist == bcdist) angle = angles(bcdist, acdist, abdist);

        if (angle == 1) cout << "DunkakTriangle";
        else if (angle == 0) cout << "JikkakTriangle";
        else if (angle == -1)cout << "YeahkakTriangle";
    }
    
}
