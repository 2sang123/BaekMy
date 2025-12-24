#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x, y, z, u, v, w;
    cin >> x >> y >> z >> u >> v >> w;
    int a = u / 100 * x;
    int b = v / 50 * y;
    int c = w / 20 * z;
    cout << a + b + c;
}
