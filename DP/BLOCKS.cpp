#include <bits/stdc++.h>
using namespace std;

#define Task "DATA"
#define ll long long
#define pb push_back

const int N = 5e7 + 7;
const int INF = 1e9;
const int MOD = 1e9 + 7;

vector<ll> dp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(Task".INP", "r")) {
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }
    int n, k;
    cin >> n >> k;
    dp.pb(0);
    dp.pb(0);
    dp.pb(1 % k);
    dp.pb(2 % k);
    for (int i = 4; i <= n; i++) {
        ll x = 3 * dp[i - 1] - dp[i - 2];
        while (x >= k) x -= k;
        while (x < 0) x += k;
        dp.pb(x);
    }
    cout << dp[n];
    return 0;
}
