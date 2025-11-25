#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

double cuts(vector<double> a, int k)
{
    double c = 0;
    for (int i = 0; i < k; i++)
    {
        a.erase(a.begin());
        a.pop_back();
    }
    for (int i = 0; i < a.size(); i++)
    {
        c += a[i];
    }
    return c / a.size();
}

double corrs(vector<double> a, int k)
{
    double c = 0;
    for (int i = 0; i < k; i++)
    {
        a[i] = a[k];
        a[a.size() - 1 - i] = a[a.size() - k-1];
    }
    for (int i = 0; i < a.size(); i++)
    {
        c += a[i];
    }
    return c / a.size();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<double> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    double cut = cuts(arr, k);
    double corr = corrs(arr, k);
    cut = std::round(cut * 100) / 100;
    corr = std::round(corr * 100) / 100;
    cout.precision(2);
    cout << fixed;
    cout << cut << '\n' << corr;
}
