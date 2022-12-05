/**
 *  author: souravrax
 *  created: 04.12.2022 10:28:52
**/
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define len(x) int((x).size())
using ll = long long;
using vi = vector<int>;
inline int intersects(int a, int b, int c, int d) { return c >= a && c <= b; }
int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string line;
    ll sum = 0, sum2 = 0;
    while (getline(cin, line)) {
        replace(all(line), ',', ' ');
        replace(all(line), '-', ' ');
        stringstream ss(line);
        vi have; int num;
        while (ss >> num) have.push_back(num);
        sum += (have[0] <= have[2] && have[3] <= have[1]) || (have[0] >= have[2] && have[1] <= have[3]);
        sum2 += intersects(have[0], have[1], have[2], have[3]) || intersects(have[2], have[3], have[0], have[1]);
    }
    cout << sum << ' ' << sum2 << endl;
}

