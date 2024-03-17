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

const int N = 1e6 + 6;
const ll INF = 1e18;
const int MOD = 1e9 + 7;

int n, m, k;
int s[20], pos[N];
vector<ii> adj[N];

vector<ll> dijkstra(int src) {
    vector<ll> dist(n, INF);
    dist[src] = 0;
    priority_queue<li, vector<li>, greater<li>> pq;
    pq.push(mp(0, src));
    vector<bool> vis(n, 0);
    while (!pq.empty()) {
        li u = pq.top();
        pq.pop();
        if (vis[u.S]) continue;
        for (auto e : adj[u.S]) {
            int v = e.F, w = e.S;
            if (dist[v] > dist[u.S] + 1LL * w) {
                dist[v] = dist[u.S] + 1LL * w;
                pq.push(mp(dist[v], v));
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(Task".INP", "r")) {
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> s[i];
        s[i]--;
    }
    while (m--) {
        int x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        adj[x].pb(mp(y, w));
    }

    vector<vector<ll>> dist(k);
    for (int i = 0; i < k; i++) dist[i] = dijkstra(s[i]);
    vector<ll> from0 = dijkstra(0);

    vector<vector<ll>> dp(1 << k, vector<ll> (k, INF));
    for (int i = 0; i < k; i++)
        if (from0[s[i]] != INF) dp[1 << i][i] = from0[s[i]];

    for (int mask = 0; mask < (1 << k); mask++) {
        for (int i = 0; i < k; i++)
            if (dp[mask][i] != INF)
                for (int j = 0; j < k; j++)
                    if ((mask >> j) % 2 == 0)
                        dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][i] + dist[i][s[j]]);
    }

    ll ans = INF;
    for (int i = 0; i < k; i++)
        if (dp[(1 << k) - 1][i] != INF)
            ans = min(ans, dp[(1 << k) - 1][i] + dist[i][0]);
    if (ans == INF) cout << -1;
    else cout << ans;
    return 0;
}

