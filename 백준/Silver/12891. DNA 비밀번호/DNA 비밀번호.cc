#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int check(int a, int c, int g, int t, int ta, int tc, int tg, int tt) {
    if (ta >= a && tc >= c && tg >= g && tt >= t) return 1;
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int s, p;
    cin >> s >> p;
    string dna;
    cin >> dna;
    int a, c, g, t;
    cin >> a >> c >> g >> t;
    int str = dna.size();
    vector<int> mask(str, 1);
    for (int i = 0; i < p; i++)
    {
        mask[i] = 0;
    }
    int ta = 0, tc = 0, tg = 0, tt = 0;
    int cnt = 0;
    for (int i = 0; i < p; i++) {
        if (dna[i] == 'A') ta++;
        else if (dna[i] == 'C') tc++;
        else if (dna[i] == 'G') tg++;
        else if (dna[i] == 'T') tt++;
    }
    cnt += check(a, c, g, t, ta, tc, tg, tt);


    for (int i = p; i < s; i++) {
        char next = dna[i];
        if (next == 'A') ta++;
        else if (next == 'C') tc++;
        else if (next == 'G') tg++;
        else if (next == 'T') tt++;

        char prev = dna[i - p];
        if (prev == 'A') ta--;
        else if (prev == 'C') tc--;
        else if (prev == 'G') tg--;
        else if (prev == 'T') tt--;

        cnt += check(a, c, g, t, ta, tc, tg, tt);
    }

    cout << cnt;
}
