#include <iostream>
using namespace std;

int getYear(int M, int N, int x, int y) 
{
    for (int k = 0; k < N; ++k) {
        int year = x + M * k;
        int currentY = year % N == 0 ? N : year % N;
        if (currentY == y)
            return year;
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        cout << getYear(M, N, x, y) << '\n';
    }
    return 0;
}
