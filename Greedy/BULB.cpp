#include <bits/stdc++.h>
using namespace std;

#define Task "DATA"
#define ll long long
#define pb push_back
#define F first
#define S second
#define mp make_pair

typedef pair<int, int> ii;

const int N = 1e6 + 6;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int x[N], t[N];
ii a[N];

bool cmp(ii &x, ii & y) {
    return x.S < y.S;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(Task".INP", "r")) {
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> t[i];
        a[i] = mp(x[i] - t[i], x[i] + t[i]);
    }
    sort(a + 1, a + n + 1, cmp);
    int ans = 0, preY = -INF;
    for (int i = 1; i <= n; i++) {
        if (a[i].F >= preY) {
            ans++;
            preY = a[i].S;
        }
    }
    cout << ans;
    return 0;
}

