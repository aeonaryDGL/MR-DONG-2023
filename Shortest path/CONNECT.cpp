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

const int N = 5e2 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int m, n;
int a[N][N], f[N][N][2][2], vis[N][N][2][2], Left[N][N], Right[N][N];
string s;
priority_queue<lii, vector<lii>, greater<lii>> pq;

struct Node {
    int D, x, y;
    bool L, R;

    bool operator < (const Node &other) const {
        return D > other.D;
    }
};

priority_queue<Node> pq2;

bool check(int x, int y) {
    return x >= 1 && x <= m && y >= 1 && y <= n;
}

void dijkstraLeft(int s) {
    vector<vector<bool>> vis(m + 1, vector<bool> (n + 1, 0));
    while (!pq.empty()) {
        lii u = pq.top();
        pq.pop();
        int i = u.S.F, j = u.S.S;
        if (vis[i][j]) continue;
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k], y = j + dy[k];
            if (!check(x, y)) continue;
            int w = abs(s - a[i][j]);
            if (Left[x][y] > Left[i][j] + w) {
                Left[x][y] = Left[i][j] + w;
                pq.push(mp(Left[x][y], mp(x, y)));
            }
        }
    }
}

void dijkstraRight(int s) {
    vector<vector<bool>> vis(m + 1, vector<bool> (n + 1, 0));
    while (!pq.empty()) {
        lii u = pq.top();
        pq.pop();
        int i = u.S.F, j = u.S.S;
        if (vis[i][j]) continue;
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k], y = j + dy[k];
            if (!check(x, y)) continue;
            int w = abs(s - a[i][j]);
            if (Right[x][y] > Right[i][j] + w) {
                Right[x][y] = Right[i][j] + w;
                pq.push(mp(Right[x][y], mp(x, y)));
            }
        }
    }
}

void dijkstra2(int s) {
    Node node;
    while (!pq2.empty()) {
        Node u = pq2.top();
        pq2.pop();
        int x = u.x, y = u.y;
        bool L = u.L, R = u.R;
        if (vis[x][y][L][R]) continue;
        vis[x][y][L][R] = 1;

        if (!L && !R && f[x][y][1][1] > f[x][y][L][R] + Left[x][y] + Right[x][y]) {
            f[x][y][1][1] = f[x][y][L][R] + Left[x][y] + Right[x][y];
            node = {f[x][y][1][1], x, y, 1, 1};
            pq2.push(node);
        }
        if (!L && f[x][y][1][R] > f[x][y][L][R] + Left[x][y]) {
            f[x][y][1][R] = f[x][y][L][R] + Left[x][y];
            node = {f[x][y][1][R], x, y, 1, R};
            pq2.push(node);
        }
        if (!R && f[x][y][L][1] > f[x][y][L][R] + Right[x][y]) {
            f[x][y][L][1] = f[x][y][L][R] + Right[x][y];
            node = {f[x][y][L][1], x, y, L, 1};
            pq2.push(node);
        }
        for (int i = 0; i < 4; i++) {
            int c = x + dx[i], d = y + dy[i];
            if (!check(c, d)) continue;
            int w = abs(a[c][d] - s);
            if (f[c][d][L][R] > f[x][y][L][R] + w) {
                f[c][d][L][R] = f[x][y][L][R] + w;
                node = {f[c][d][L][R], c, d, L, R};
                pq2.push(node);
            }
        }
    }
}

int solve(int s) {
    memset(Left, 0x2f, sizeof(Left));
    for (int i = 1; i <= m; i++)
        pq.push(mp(0, mp(i, 1))), Left[i][1] = 0;
    dijkstraLeft(s);

    memset(Right, 0x2f, sizeof(Right));
    for (int i = 1; i <= m; i++)
        pq.push(mp(0, mp(i, n))), Right[i][n] = 0;
    dijkstraRight(s);

    Node node;
    memset(f, 0x2f, sizeof(f));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        node = {abs(s - a[1][i]), 1, i, 0, 0};
        pq2.push(node);
        f[1][i][0][0] = abs(s - a[1][i]);
    }
    dijkstra2(s);
    int ans = INF;
    for (int i = 1; i <= n; i++) ans = min(ans, f[m][i][1][1]);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(Task".INP", "r")) {
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> s;
        s = " " + s;
        for (int j = 1; j <= n; j++) a[i][j] = (s[j] - '0');
    }

    int ans = INF;
    for (int s = 0; s <= 9; s++) ans = min(ans, solve(s));
    cout << ans;
    return 0;
}

