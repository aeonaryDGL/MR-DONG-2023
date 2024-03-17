#include <bits/stdc++.h>
using namespace std;

#define Task "DATA"
#define ll long long
#define pb push_back

const int N = 1e6 + 6;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int n;
int a[10], cnt[10];
int dp[30][30][30][30][30];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(Task".INP", "r")) {
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> newA[n];
    for (int i = 0; i < n; i++) {
        int x = a[i];
        cnt[i] = 0;
        while (x > 0) {
            newA[i].pb(x);
            if (x % 2 != 0) x--;
            else x /= 2;
            if (x == 0) nen[i].pb(x);
        }
        reverse(newA[i].begin(), newA[i].end());
    }

    dp[0][0][0][0][0] = 1;
    for (int i = 0; i < newA[0].size(); i++)
        for (int j = 0; j < newA[1].size(); j++)
            for (int k = 0; k < newA[2].si)
    return 0;
}

