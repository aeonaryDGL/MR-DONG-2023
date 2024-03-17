#include <bits/stdc++.h>
using namespace std;

#define Task "DATA"
#define ll long long
#define pb push_back
#define F first
#define S second
#define mp make_pair

typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> iii;
typedef pair<ll, int> li;

const int N = 1e3 + 3;
const ll INF = 1e18;
const int MOD = 1e9 + 7;

int n, m, D;
ll s;
ll p[N];
vector<ii> adj[N];
il f[N][N];

struct Node {
    int i, j, diamond;
    ll money;

    bool operator < (const Node &other) const {
        return (diamond < other.diamond) ||
        (diamond == other.diamond && money > other.money);
    }
};

void dijkstra() {
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) f[i][j] = mp(-1, -1);
    f[1][1] = mp(D, s);
    priority_queue<Node> pq;
    Node node;
    node = {1, 1, D, s};
    pq.push(node);
    vector<bool> vis(n + 1, 0);
    while (!pq.empty()) {
        Node u = pq.top();
        pq.pop();
        int i = u.i, j = u.j, d = u.diamond;
        ll m = u.money;
        if (vis[i]) continue;
        vis[i] = 1;
        //cout << i << " " << j << " " << d << " " << m << "\n";
        for (auto e : adj[i]) {
            int v = e.F, w = e.S;
            if (p[i] > p[j]) j = i;
            if (m - w >= 0) {
                if (d > f[v][j].F) {
                    f[v][j] = mp(d, m - w);
                    node = {v, j, d, m - w};
                    pq.push(node);
                }
            } else {
                int sale = abs(m - w) / p[j] + (abs(m - w) % p[j] != 0);
                if (sale > d) continue;
                //cout << i << " " << v << " " << j << " " << d << " " << sale << "\n";
                if (m - w + sale * p[j] < 0) continue;
                if (d - sale > f[v][j].F) {
                    f[v][j] = mp(d - sale, m - w + sale * p[j]);
                    node = {v, j, d - sale, m - w + sale * p[j]};
                    pq.push(node);
                }
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
    cin >> n >> m >> s >> D;
    for (int i = 1; i <= n; i++) cin >> p[i];
    while (m--) {
        int x, y, c;
        cin >> x >> y >> c;
        adj[x].pb(mp(y, c));
    }
    dijkstra();
    int ans = -1;
    for (int i = 1; i <= n; i++) ans = max(ans, f[n][i].F);
    cout << ans;
    return 0;
}
