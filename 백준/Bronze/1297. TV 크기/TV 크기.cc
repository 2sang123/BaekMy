#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int d, h, w;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> d >> h >> w;

    int disth = sqrt(pow(d, 2) * pow(h, 2) / (pow(w, 2)+pow(h,2)));
    int distw = sqrt(pow(d, 2) * pow(w, 2) / (pow(h, 2)+pow(w,2)));

    cout << disth <<' ' << distw;
}
