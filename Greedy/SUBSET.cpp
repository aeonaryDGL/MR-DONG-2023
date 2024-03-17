#include <bits/stdc++.h>
using namespace std;

#define Task "DATA"
#define ll long long
#define pb push_back
#define F first
#define S second

const int N = 1e6 + 6;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int n;
ll l, r;
ll a[N];
pair<ll, vector<int>> x[1 << 21];

void sub2() {
    int leftSize = n / 2, rightSize = n - leftSize;
    int sz = 0;
    for (int i = 0; i < (1 << leftSize); i++) {
        ll sum = 0;
        sz++;
        for (int j = 0; j < leftSize; j++)
            if (i & (1 << j)) {
                sum += a[j + 1];
                x[sz].S.pb(j + 1);
            }
        x[sz].F = sum;
    }
    sort(x + 1, x + sz + 1);

    for (int i = 0; i < (1 << rightSize); i++) {
        ll sum = 0;
        vector<int> pos;
        for (int j = 0; j < rightSize; j++)
            if (i & (1 << j)) {
                sum += a[leftSize + j + 1];
                pos.pb(leftSize + j + 1);
            }
        int lo = 1, hi = sz, p = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (x[mid].F + sum >= l) {
                p = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        if (p == -1 || x[p].F + sum > r) continue;
        cout << x[p].S.size() + pos.size() << "\n";
        for (int i : x[p].S) cout << i << " ";
        for (int i : pos) cout << i << " ";
        cout << "\n";
        return;
    }
    cout << -1 << "\n";
}

vector<int> sum[101010];

void sub3() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= r; j++) {
            if (sum[j].size() > 0) continue;
            if (j - a[i] == 0) sum[j].pb(i);
            else if (j - a[i] > 0 && sum[j - a[i]].size() > 0) {
                if (find(sum[j - a[i]].begin(), sum[j - a[i]].end(), i) != sum[j - a[i]].end()) continue;
                for (int v : sum[j - a[i]]) sum[j].pb(v);
                sum[j].pb(i);
            }
        }

    int ans;
    for (int i = l; i <= r; i++)
        if (sum[i].size() > 0) {
            ans = i;
            break;
        }
    cout << sum[ans].size() << "\n";
    for (auto v : sum[ans]) cout << v << " ";
    cout << "\n";
}

void sub4() {
    cout << r / a[1] << "\n";
    for (int i = 1; i <= r / a[i]; i++) cout << i << " ";
    cout << "\n";
}

ll pre[N];
pair<ll, int> y[N];

void sub6() {
    for (int i = 1; i <= n; i++) {
        y[i].F = a[i];
        y[i].S = i;
    }
    sort(y + 1, y + n + 1);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + y[i].F;
    for (int k = 1; k <= n; k++) {
        if (!(pre[k] <= r && pre[n] - pre[n - k] >= l)) continue;
        for (int i = k; i <= n; i++)
        if (pre[i] - pre[i - k] >= l && pre[i] - pre[i - k] <= r) {
            cout << k << "\n";
            vector<int> ans;
            for (int j = i - k + 1; j <= i; j++) ans.pb(y[j].S);
            sort(ans.begin(), ans.end());
            for (int v : ans) cout << v << " ";
            return;
        }
    }
    cout << -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(Task".INP", "r")) {
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }
    cin >> n >> l >> r;
    bool isSub4 = 1, isSub5 = 1;
    for (int i = 1; i <= n; i++)  {
        cin >> a[i];
        if (i > 1 && a[i] != a[i - 1]) isSub4 = 0;
        if (a[i] != i) isSub5 = 0;
    }
    if (n <= 40) sub2();
    else if (n <= 80 && r <= 100000) sub3();
    else if (isSub4) sub4();
    else sub6();
    return 0;
}

