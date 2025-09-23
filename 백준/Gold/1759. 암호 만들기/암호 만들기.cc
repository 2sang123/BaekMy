#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int n;
int c;
bool isVowel(char ch)
{
    string vowels = "aeiou";
    return vowels.find(ch) != string::npos;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> c;
    vector<char> arr;
    vector<int> temp(c);
    for (int i = 0; i < c; i++)
    {
        char ch;
        cin >> ch;
        arr.push_back(ch);
    }
    sort(arr.begin(), arr.end());
    fill(temp.begin(), temp.begin() + n, 1);
    do
    {
        string s;
        int nv = 0;
        int v = 0;
        for (int i = 0; i < c; i++)
        {
            if (temp[i])
            {
                s += arr[i];
                if (!isVowel(arr[i])) nv++;
                else v++;
            }
        }
        if (nv < 2 || v<1) continue;
        cout << s;
        cout << '\n';
    } while (prev_permutation(temp.begin(), temp.end()));
}
