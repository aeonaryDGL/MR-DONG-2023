#include <bits/stdc++.h>
using namespace std;

#define Task "DATA"
#define ll long long
#define pb push_back
#define F first
#define S second

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<ll, int> li;

const int N = 1e6 + 6;
const ll INF = 1e18;
const int MOD = 1e9 + 7;

int n, m;
int p[N];
vector<ii> adj[N];
ll ans[N];
bool vis[N];

void dijkstra() {
    for (int i = 1; i <= n; i++) ans[i] = INF;
    ans[n + 1] = 0;
    priority_queue<li, vector<li>, greater<li>> pq;
    pq.push(make_pair(0, 0));
    while (!pq.empty()) {
        li u = pq.top();
        pq.pop();
        if (vis[u.S]) continue;
        vis[u.S] = 1;
        for (auto e : adj[u.S]) {
            int v = e.F, w = e.S;
            if (ans[v] > ans[u.S] + 1LL * w) {
                ans[v] = ans[u.S] + 1LL * w;
                pq.push(make_pair(ans[v], v));
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
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        adj[0].pb(make_pair(i, p[i]));
        adj[i].pb(make_pair(0, p[i]));
    }
    while (m--) {
        int x, y, c;
        cin >> x >> y >> c;
        adj[x].pb(make_pair(y, 2 * c));
        adj[y].pb(make_pair(x, 2 * c));
    }
    dijkstra();
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}

