#include <bits/stdc++.h>
using namespace std;

#define Task "DATA"
#define ll long long
#define pb push_back
#define F first
#define S second
#define mp make_pair

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ll, int> li;

const int N = 1e6 + 6;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int n, m, k;
vector<iii> tmp;
vector<ii> adj[N];
vector<int> v;
ll dist[1000][1000];
map<int, int> nen;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(Task".INP", "r")) {
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        tmp.pb(mp(c, mp(x, y)));
    }
    sort(tmp.begin(), tmp.end());
    vector<bool> vis(n + 1, 0);
    for (int i = 0; i < min(k, m); i++) {
        int x = tmp[i].S.F, y = tmp[i].S.S;
        if (!vis[x]) v.pb(x), vis[x] = 1;
        if (!vis[y]) v.pb(y), vis[y] = 1;
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for (int ver : v) nen[ver] = ++cnt;
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i < min(k, m); i++) {
        int x = tmp[i].S.F, y = tmp[i].S.S;
        x = nen[x], y = nen[y];
        dist[x][y] = tmp[i].F;
        dist[y][x] = tmp[i].F;
    }
    for (int k = 1; k <= cnt; k++)
        for (int i = 1; i <= cnt; i++)
            for (int j = 1; j <= cnt; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    vector<int> ans;
    for (int i = 1; i <= cnt; i++)
        for (int j = i + 1; j <= cnt; j++)
            ans.pb(dist[i][j]);
    sort(ans.begin(), ans.end());
    cout << ans[k - 1];
    return 0;
}

