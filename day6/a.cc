#include <bits/stdc++.h>
using namespace std;
#define len(x) int((x).size())
int find_pos(const string& s, int size) {
    array<int, 26> f{};
    int freq = 0;
    for (int l = 0, r = 0; r < len(s); r++) {
        if (f[s[r] - 'a']++ == 0) freq++;
        if (freq == size) return r + 1;
        if (r >= size - 1) {
            freq -= --f[s[l++] - 'a'] == 0;
        }
    }
    return string::npos;
}

int32_t main() {
    string s;
    cin >> s;
    cout << find_pos(s, 4) << ' ' << find_pos(s, 14) << endl;
}
