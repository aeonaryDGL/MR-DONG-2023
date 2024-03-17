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
const ll INF = 1e18;
const int MOD = 1e9 + 7;

int n, A, B, D;
ii times[N];

void sub2() {
    vector<int> v;
    int sumT = 0;
    for (int i = 1; i <= n; i++) v.pb(i), sumT += times[i].F;
    ll ans = INF;
    for (int p = A; p + sumT <= B; p++) {
        do {
            int s = p;
            ll sum = 0;
            for (auto i : v) {
                s += times[i].F;
                sum += 1LL * abs(s - D) * times[i].S;
            }
            ans = min(ans, sum);
        } while (next_permutation(v.begin(), v.end()));
    }
    cout << ans << "\n";
}

bool cmp(ii &x, ii &y) {
    return x.F * y.S < y.F * x.S;
}

void sub3() {
    sort(times + 1, times + n + 1, cmp);
    ll ans = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += times[i].F;
        ans += sum * times[i].S;
    }
    cout << ans << "\n";
}

void sub4() {
    sort(times + 1, times + n + 1, cmp);
    ll ans = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        ans += sum * times[i].S;
        sum += times[i].F;
    }
    cout << ans << "\n";
}

void sub5() {
    ll ans = INF;
    for (int mask = 0; mask < (1 << n); mask++) {
        ii x[20], y[20];
        int sz1 = 0, sz2 = 0, sumT = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) x[++sz1] = times[i + 1], sumT += times[i + 1].F;
            else y[++sz2] = times[i + 1];
        }
        if (sumT > D - A) continue;
        sort(x + 1, x + sz1 + 1, cmp);
        sort(y + 1, y + sz2 + 1, cmp);
        ll res = 0, sum = 0;
        for (int i = 1; i <= sz1; i++) {
            res += sum * x[i].S;
            sum += x[i].F;
        }
        sum = 0;
        for (int i = 1; i <= sz2; i++) {
            sum += y[i].F;
            res += sum * y[i].S;
        }
        ans = min(ans, res);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(Task".INP", "r")) {
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }
    cin >> n >> A >> B >> D;
    for (int i = 1; i <= n; i++) cin >> times[i].F >> times[i].S;
    if (n <= 8) sub2();
    else if (A == D) sub3();
    else if (B == D) sub4();
    else if (n <= 20) sub5();
    return 0;
}

