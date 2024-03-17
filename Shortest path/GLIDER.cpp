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

ii a[N];
vector<ii> adj[N];
ll dist[N];
bool vis[N];

void dijkstra(int n) {
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[1] = 0;
    priority_queue<li, vector<li>, greater<li>> pq;
    pq.push(mp(0, 1));
    while (!pq.empty()) {
        li u = pq.top();
        pq.pop();
        if (vis[u.S]) continue;
        vis[u.S] = 1;
        for (auto e : adj[u.S]) {
            int v = e.F, w = e.S;
            if (dist[v] > dist[u.S] + 1LL * w) {
                dist[v] = dist[u.S] + 1LL * w;
                pq.push(mp(dist[v], v));
            }
        }
    }
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
    for (int i = 1; i <= n; i++) cin >> a[i].F >> a[i].S;

    sort(a + 1, a + n + 1);

    for (int i = 2; i <= n; i++) adj[i].pb(mp(i - 1, 0));
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1LL * a[i].S;
        int l = i + 1, r = n, j = i;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid].F - a[i].F - a[i].S <= 0) l = (j = mid) + 1;
            else r = mid - 1;
        }
        adj[i].pb(mp(j, 0));
        if (j + 1 <= n) adj[i].pb(mp(j + 1, a[j + 1].F - a[i].F - a[i].S));
    }

    dijkstra(n);
    cout << dist[n] + ans;
    return 0;
}
