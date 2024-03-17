#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3"
#pragma GCC target("sse4")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define Task "DATA"
#define ll long long
#define pb push_back

const int N = 367;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int m, n, k;
string a[N];
int dp[N][N][N][2];

int calc(int x, int y, int u, int r) {
    int v = m - u + 1 + n + 1 - x - y;
    if (x < 1 || x > m || y < 1 || y > n) return 0;
    if (u < 1 || u > m || v < 1 || v > n) return 0;
    if (x > u || (x == u && y > v)) return 0;
    if (dp[x][y][u][r] != -1) return dp[x][y][u][r];
    if (x == u && y == v) {
        dp[x][y][u][0] = 1;
        dp[x][y][u][1] = 0;
        return dp[x][y][u][r];
    }
    if ((x == u && v == y + 1) || (u == x + 1 && y == v)) {
        dp[x][y][u][0] = (a[x][y] == a[u][v]);
        dp[x][y][u][1] = (a[x][y] != a[u][v]);
        return dp[x][y][u][r];
    }
    ll res = (((calc(x + 1, y, u - 1, 0) + calc(x, y + 1, u - 1, 0)) % k + calc(x + 1, y, u, 0)) % k + calc(x, y + 1, u, 0)) % k;
    if (a[x][y] != a[u][v]) {
        dp[x][y][u][0] = 0;
        dp[x][y][u][1] = res;
    } else {
        dp[x][y][u][0] = res;
        dp[x][y][u][1] = (((calc(x + 1, y, u - 1, 1) + calc(x, y + 1, u - 1, 1)) % k + calc(x + 1, y, u, 1)) % k + calc(x, y + 1, u, 1)) % k;
    }
    return dp[x][y][u][r];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(Task".INP", "r")) {
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        a[i] = " " + a[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << (calc(1, 1, m, 0) + calc(1, 1, m, 1)) % k;;
    return 0;
}
