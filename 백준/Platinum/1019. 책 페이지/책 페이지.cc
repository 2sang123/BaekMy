#include <iostream>
using namespace std;

long long digit[10] = { 0, };
void  digitCountUpTo(long long x) {
    long long factor = 1;

    while (x / factor > 0) {
        long long lower = x % factor;
        long long current = (x / factor) % 10;
        long long upper = x / (factor * 10);

        for (int i = 0; i < 10; i++)
        {
            if (i == 0 && upper == 0) 
                continue;

            digit[i] += upper * factor;

            if (i == 0) {
                digit[0] -= factor;  // 보정 필요
                if (upper == 0) {
                    digit[0] += factor;  // 맨 앞자리에서 upper==0이면 빼면 안됨
                }
            }

            if (i < current)
            {
                digit[i] += factor;
            }
            else if (i == current)
            {
                digit[i] += lower + 1;
            }
        }
        factor *= 10;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A;
    cin >> A;

    digitCountUpTo(A);
    for (int i = 0; i < 10; i++)
    {
        cout << digit[i] << ' ';
    }
}
