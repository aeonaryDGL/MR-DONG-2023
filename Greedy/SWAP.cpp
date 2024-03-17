#include <bits/stdc++.h>
using namespace std;

#define Task "DATA"
#define ll long long
#define pb push_back

const int N = 1e6 + 6;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(Task".INP", "r")) {
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int l = 1; l <= n && k > 0; l++) {
        int maxNum = a[l], maxPos = l;
        for (int r = l + 1; r <= min(l + k, n); r++)
            if (a[r] > maxNum) maxNum = a[r], maxPos = r;
        if (maxPos == l) continue;
        for (int i = maxPos; i >= l + 1; i--) swap(a[i], a[i - 1]);
        k -= maxPos - l;
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}

