#include <iostream>
#include <algorithm>
using namespace std;

double a, b, c;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c;
    double d = a * c / b;
    cout << d;
}
