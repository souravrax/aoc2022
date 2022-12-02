/**
 *  author: souravrax
 *  created: 02.12.2022 10:54:22
**/
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define len(x) int((x).size())
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename TC, typename T = typename enable_if<!is_same<TC, string>::value, typename TC::value_type>::type> 
ostream& operator<<(ostream &os, const TC &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
struct dbg {
#ifdef LOCAL
    ~dbg() { cerr << endl; }
    template<typename T> dbg& operator<<(const T& args) { cerr << args; return *this; }
#else
    template<typename T> dbg& operator<<(__attribute__((unused))const T& args) { return *this; }
#endif
};
#define show(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int, int>;

void solve() {
    string line;
    ll sum1 = 0, sum2 = 0;
    while (getline(cin, line)) {
        int a = line[0] - 'A';
        int b = line[1] - 'B';
        sum1 += (a == b) * 3 + ((b - a + 3) % 3 == 1) * 6 + b + 1;
        sum2 += b * 3 + (a + b - 1 + 3) % 3 + 1;
    }
    cout << sum1 << ' ' << sum2 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    for (int t = 1; t <= tt; t++) {
        solve();
    }
}

