/**
 *  author: souravrax
 *  created: 03.12.2022 10:30:35
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

void solve1() {
    string line;
    long long sum1 = 0;
    while (getline(cin, line)) {
        string a = line.substr(0, line.length() / 2);
        string b = line.substr(line.length() / 2);
        multiset<char> st(all(a));
        for (char& c : b) {
            if (st.count(c)) {
                ll value = tolower(c) - 'a';
                sum1 += (value + 1) * isupper(c) * 26;
                break;
            }
        }
    }
    cout << sum1 << endl;
}
void solve2() {
    string line;
    vector<string> lines;
    ll sum = 0;
    while (getline(cin, line)) {
        lines.push_back(line);
        if (lines.size() == 3) {
            map<char, int> mp;
            for (string& i : lines) {
                for (char c : set<char>(all(i))) {
                    mp[c]++;
                }
            }
            for (auto& [k, v] : mp) {
                if (v == 3) {
                    ll value = tolower(k) - 'a';
                    sum += (value + 1) * isupper(k) * 26;
                    break;
                }
            }
            lines.clear();
        }
    }
    cout << sum << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve1();
    solve2();
}

