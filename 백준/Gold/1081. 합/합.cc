#include <iostream>
using namespace std;

long long digitSumUpTo(long long x) {
    long long sum = 0;
    long long factor = 1;

    while (x / factor > 0) {
        long long lower = x % factor;                   
        long long current = (x / factor) % 10;          
        long long upper = x / (factor * 10);            

        sum += upper * factor * 45;

        sum += current * (current - 1) / 2 * factor + (current * (lower + 1));

        factor *= 10;
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long L, U;
    cin >> L >> U;

    long long result = digitSumUpTo(U) - digitSumUpTo(L - 1);
    cout << result << "\n";
}
