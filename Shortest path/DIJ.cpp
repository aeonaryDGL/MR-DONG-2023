#include <bits/stdc++.h>
using namespace std;

#define Task "DATA"
#define ll long long
#define pb push_back
#define F first
#define S second
#define mp make_pair

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<ll, int> li;
typedef pair<ll, ii> lii;

const int N = 5e2 + 10;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int n, m, k;
ll dist[N][N], cur[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(Task".INP", "r")) {
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }
    memset(dist, 0x3f, sizeof(dist));
    cin >> n >> m >> k;
    while (m--) {
        int x, y, c;
        cin >> x >> y >> c;
        dist[x][y] = min(dist[x][y], 1LL * c);
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    while (k--) {
        memset(cur, 0x3f, sizeof(cur));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) cur[i][j] = dist[i][j];

        int e;
        cin >> e;
        while (e--) {
            int u, v, c;
            cin >> u >> v >> c;
            cur[u][v] = min(cur[u][v], 1LL * c);
        }

        for (int g = n + 1; g <= n + 3; g++) {
            for (int i = 1; i <= g; i++)
                for (int j = 1; j <= g; j++)
                    cur[g][i] = min(cur[g][i], cur[g][j] + cur[j][i]),
                    cur[i][g] = min(cur[i][g], cur[i][j] + cur[j][g]);

            for (int i = 1; i <= n + 3; i++)
                for (int j = 1; j <= n + 3; j++)
                    cur[i][j] = min(cur[i][j], cur[i][g] + cur[g][j]);
        }

        ll ans = 0;
        for (int i = 1; i <= n + 3; i++)
            for (int j = 1; j <= n + 3; j++)
                if (i != j && cur[i][j] <= INF) ans += cur[i][j];
        cout << ans << "\n";
    }

    return 0;
}
