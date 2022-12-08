/**
 *  author: souravrax
 *  created: 08.12.2022 10:33:47
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

string join(vector<string>& v, char delim = ' ') {
    if (len(v) == 0) return "";
    string ans = v[0];
    for (int i = 1; i < len(v); i++) ans += string(1, delim) + v[i];
    return ans;
}

string uppercase(string s) {
    for (char& c : s) c = toupper(c);
    return s;
}

string lowercase(string s) {
    for (char& c : s) c = tolower(c);
    return s;
}

string capitalize(string s) {
    if (len(s) == 0) return s;
    for (char& c : s) c = tolower(c);
    s[0] = toupper(s[0]);
    return s;
}
}; // namespace std

// mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
__attribute__((unused))const int mod = (int)1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
#ifndef LOCAL
    cin.tie(nullptr);
#endif
    vector<vector<int>> matrix;
    string line;
    while (getline(cin, line)) {
        vector<int> now;
        for (int i = 0; i < len(line); i++) {
            now.push_back(line[i] - '0');
        }
        matrix.push_back(now);
    }
    int n = len(matrix);
    int m = len(matrix[0]);

    // Problem 1

    vector<vector<int>> grid(n, vector<int>(m, INT_MAX));

    for (int i = 0; i < n; i++) {
        int mx_left = 0, mx_right = 0;
        for (int j = 0; j < m; j++) {
            grid[i][j] = min(grid[i][j], mx_left);
            mx_left = max(mx_left, matrix[i][j]);
        }
        for (int j = m - 1; ~j; j--) {
            grid[i][j] = min(grid[i][j], mx_right);
            mx_right = max(mx_right, matrix[i][j]);
        }
    }
    for (int j = 0; j < m; j++) {
        int mx_top = 0, mx_bottom = 0;
        for (int i = 0; i < n; i++) {
            grid[i][j] = min(grid[i][j], mx_top);
            mx_top = max(mx_top, matrix[i][j]);
        }
        for (int i = n - 1; ~i; i--) {
            grid[i][j] = min(grid[i][j], mx_bottom);
            mx_bottom = max(mx_bottom, matrix[i][j]);
        }
    }

    int ans = n * 2 + m * 2 - 4;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (grid[i][j] < matrix[i][j]) {
                ans++;
            }
        }
    }
    
    // Problem 2

    ll ans2 = 0;
    vector<vector<vector<ll>>> val(n, vector<vector<ll>>(m));
    // left, right
    for (int i = 0; i < n; i++) {
        vector<int> dp(m, 1);
        stack<int> st;
        for (int j = 0; j < m; j++) {
            while (!st.empty() && matrix[i][st.top()] < matrix[i][j]) {
                dp[j] += dp[st.top()];
                st.pop();
            }
            st.push(j);
            val[i][j].push_back(dp[j]);
        }
        dp.assign(m, 1);
        while (!st.empty()) st.pop();
        for (int j = m - 1; ~j; j--) {
            while (!st.empty() && matrix[i][st.top()] < matrix[i][j]) {
                dp[j] += dp[st.top()];
                st.pop();
            }
            st.push(j);
            val[i][j].push_back(dp[j]);
        }
    }
    // top, bottom
    for (int j = 0; j < m; j++) {
        stack<int> st;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && matrix[st.top()][j] < matrix[i][j]) {
                dp[i] += dp[st.top()];
                st.pop();
            }
            st.push(i);
            val[i][j].push_back(dp[i]);
        }
        dp.assign(n, 1);
        while (!st.empty()) st.pop();

        for (int i = n - 1; ~i; i--) {
            while (!st.empty() && matrix[st.top()][j] < matrix[i][j]) {
                dp[i] += dp[st.top()];
                st.pop();
            }
            st.push(i);
            val[i][j].push_back(dp[i]);
        }
    }

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            val[i][j][0] -= (j + 1) == val[i][j][0];
            val[i][j][1] -= (m - j) == val[i][j][1];

            val[i][j][2] -= (i + 1) == val[i][j][2];
            val[i][j][3] -= (n - i) == val[i][j][3];
            dbg() << show(val[i][j]);
            ll v = (val[i][j][0] * val[i][j][1] * val[i][j][2] * val[i][j][3]);
            ans2 = max(ans2, v);
        }
    }

    cout << ans << ' ' << ans2 << endl;
}
