#include <bits/stdc++.h>
using namespace std;

#define Task "DATA"
#define ll long long
#define pb push_back

const int N = 1e6 + 6;
const ll INF = 1e18;
const int MOD = 1e9 + 7;

int a[N];
ll L[N], s[N], R[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(Task".INP", "r")) {
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }
    int n, k;
    cin >> n >> k;
    ll mi = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + 1LL * a[i];
        L[i] = max(0LL, s[i] - mi);
        mi = min(mi, s[i]);
    }
    ll ma = s[n];
    for (int i = n; i >= 1; i--) {
        R[i] = max(0LL, ma - s[i - 1]);
        ma = max(ma, s[i - 1]);
    }
    ll ans = -INF;
    ma = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, R[i + 1] + s[i] * k + ma);
        ma = max(ma, L[i] - s[i] * k);
    }
    cout << ans;
    return 0;
}

