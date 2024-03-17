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
typedef pair<ll, int> li;

const int N = 1e6 + 6;
const int INF = 1e9;
const int MOD = 1e9 + 7;

struct DSU {
    int n;
    vector<int> par, sz;

    void init() {
        for (int i = 1; i <= n; i++)
            par[i] = i, sz[i] = 1;
    }

    void init(int _n) {
        n = _n;
        par.resize(n + 7), sz.resize(n + 7);
        init();
    }

    int getP(int u) {
        return u ^ par[u] ? par[u] = getP(par[u]) : u;
    }

    void unite(int a, int b) {
        a = getP(a), b = getP(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }
};

struct edge {
    int u, v, c;
    bool operator < (const edge & other) {
        return c < other.c;
    }
};

struct Node {
    int u, c, mask;
    bool operator < (const Node & other) {
        return c > other.c;
    }
};

int n, k, m, t;
int iPos[N];
edge e[N];

void sub1() {
    for (int i = 1; i <= m; i++)
        cin >> e[i].u >> e[i].v >> e[i].c;
    sort(e + 1, e + m + 1);

    DSU dsu;
    dsu.init(n);
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        if (dsu.getP(e[i].u) == dsu.getP(e[i].v)) continue;
        dsu.unite(e[i].u, e[i].v), ans += e[i].c;
    }
    cout << ans << "\n";
}

vector<ii> adj[N];

void dijkstra()

void subType1() {
    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].pb(mp(v, c));
        adj[v].pb(mp(u, c));
    }


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(Task".INP", "r")) {
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }
    cin >> n >> k >> m >> t;
    for (int i = 1; i <= n; i++) iPos[i] = -1;
    for (int i = 1, pos; i <= k; i++) {
        cin >> pos;
        iPos[pos] = i;
    }
    if (t == 1 && k == n) {
        sub1();
        return 0;
    }
    if (t == 1) subType1();
    return 0;
}
