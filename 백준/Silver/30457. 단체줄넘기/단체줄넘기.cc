#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> students(n);
    for (int i = 0; i < n; i++)
    {
        cin >> students[i];
    }
    sort(students.begin(), students.end());
    int cnt = 0;
    int left = 0;
    int right = 0;
    
    for (int h : students)
    {
        if (h > left)
        {
            cnt++;
            left = h;
        }
        if (left > right)
        {
            swap(left, right);
        }
    }
    cout << cnt;
}