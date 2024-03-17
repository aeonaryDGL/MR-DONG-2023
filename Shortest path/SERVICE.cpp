#include <bits/stdc++.h>
using namespace std;

#define Task "DATA"
#define ll long long
#define pb push_back
#define F first
#define S second
#define mp make_pair

typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

const int N = 510;
const int INF = 1e9;
const int MOD = 1e9 + 7;

ll dist[N][N], opt[N][N];

void minimize(ll &x, ll y) {
    if (x > y) x = y;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(Task".INP", "r")) {
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }
    memset(dist, 0x3f, sizeof(dist));
    memset(opt, 0x3f, sizeof(opt));
    int n, m, k;
    cin >> n >> m >> k;
    while (m--) {
        int x, y, c;
        cin >> x >> y >> c;
        minimize(dist[x][y], c);
        minimize(dist[y][x], c);
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                minimize(dist[i][j], dist[i][k] + dist[k][j]);

    for (int i = 1; i <= n; i++) dist[i][i] = opt[i][i] = 0;

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (k != i && dist[i][k] + dist[k][j] == dist[i][j])
                    minimize(opt[i][j], dist[i][k]);

    while (k--) {
        int x, y, z;
        cin >> x >> y >> z;

        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            pll mi = {INF, INF};
            mi = min(mi, {dist[i][x], opt[i][x]});
            mi = min(mi, {dist[i][y], opt[i][y]});
            mi = min(mi, {dist[i][z], opt[i][z]});
            ans += mi.S;
        }

        cout << ans * 100 << "\n";
    }
    return 0;
}
