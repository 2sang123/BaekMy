#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int arr[26] = { 0, };

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            arr[s[i]-'a']++;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            arr[s[i] - 'A']++;
        }
    }
    int lot = 0;
    int d = 0;
    char out = 0;
    for (int i = 0; i < 26; i++)
    {
        if (lot < arr[i])
        {
            d = 0;
            lot = arr[i];
            out = i + 'A';
        }
        else if (lot == arr[i])
        {
            d++;
            out = '?';
        }
    }
    cout << out;
}
