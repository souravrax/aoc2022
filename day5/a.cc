/**
 *  author: souravrax
 *  created: 05.12.2022 10:32:58
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

int32_t main() {
    vector<string> st1, st2;
    for (int i = 0; i < 9; i++) {
        string line;
        getline(cin, line);
        reverse(all(line));
        st1.push_back(line);
        st2.push_back(line);
    }
    string operation;
    while (getline(cin, operation)) {
        stringstream ss(operation);
        int qt, from, to;
        ss >> qt >> from >> to;
        --from, --to;
        dbg() << show(qt) << show(from) << show(to);
        st2[to] += st2[from].substr(len(st2[from]) - qt);
        st2[from].erase(len(st2[from]) - qt);
        while (qt--) {
            st1[to].push_back(st1[from].back());
            st1[from].pop_back();
        }
    }
    string ans1, ans2;
    for (int i = 0; i < 9; i++) {
        ans1 += st1[i].back();
        ans2 += st2[i].back();
    }
    cout << ans1 << ' ' << ans2 << '\n';
}

