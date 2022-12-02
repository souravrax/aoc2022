/**
 *  author: souravrax
 *  created: 01.12.2022 21:58:07
**/

/* 
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

namespace std {
#define ar array
#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define str(x) to_string(x)
//@y_combinator
template <class F>
    struct y_combinator {
        F f;
        template <class... Args>
            decltype(auto) operator()(Args &&... args) const {
                // the lambda should take the first argument as `auto&& recurse` or similar.
                return f(*this, std::forward<Args>(args)...);
            }
    };
template <class F>
    inline y_combinator<std::decay_t<F>> make_y_combinator(F &&f) { return {std::forward<F>(f)}; }

//@Debugger
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

template <typename T> inline void ckmin(T &a, T b) { return a < b ? a = b : 0; }
template <typename T> inline void ckmax(T &a, T b) { return a > b ? a = b : 0; }
template <class K, class V>
using table = __gnu_pbds::gp_hash_table<K, V>;
template <typename K, typename V, typename Comp = std::less<K>>
using ordered_map = __gnu_pbds::tree<
K, V, Comp,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update>;
template <typename K, typename Comp = std::less<K>>
using ordered_set = ordered_map<K, __gnu_pbds::null_type, Comp>;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
__attribute__((unused))const ld PI = 3.141592653589793238f;
vector<string> split(string& s, char delim = ' ') {
    stringstream ss(s);
    replace_if(all(s), [&](char& c) { return c == delim; }, ' ');
    string token;
    vector<string> splits;
    while (ss >> token) splits.emplace_back(token);
    return splits;
}
}; // namespace std

// mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
__attribute__((unused))const int mod = (int)1e9 + 7;

void solve() {
    string line;
    ll sum = 0;
    vector<int> a;
    while (getline(cin, line)) {
        if (line == "") {
            a.push_back(sum);
            sum = 0;
        } else {
            sum += stoi(line);
        }
    }
    a.push_back(sum);
    sort(all(a), greater<>());
    cout << a[0] + a[1] + a[2] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
#ifndef LOCAL
    cin.tie(nullptr);
#endif
    int T = 1; 
    for (int test_no = 1; test_no <= T; ++test_no) {
        // cout << "Case #" << test_no << ": ";
        solve();
    }
}

// overflows? index_of_of_bound? integer_overflows? read the problem?

