#include <bits/stdc++.h>
using namespace std;

#define Task "DATA"
#define ll long long
#define pb push_back

const int N = 1e6 + 6;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int n;
int a[N], cnt[80], mask[80], p[20];
ll dp[80][1 << 19];
ll poww[N];

bool isPrime(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return 0;
    return x >= 2;
}

void init() {
    int sz = 0;
    for (int i = 2; i <= 70; i++)
        if (isPrime(i)) p[sz++] = i;

    for (int i = 1; i <= 70; i++) {
        int x = i;
        for (int j = 0; j <= 18; j++) {
            while (true) {
                if (x == 0) break;
                else if (x % p[j] == 0) {
                    x /= p[j];
                    mask[i] ^= (1 << j);
                }
                else break;
            }
        }
    }

    poww[0] = 1;
    for (int i = 1; i <= n; i++) poww[i] = (poww[i - 1] * 2) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(Task".INP", "r")) {
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    init();

    dp[0][0] = 1;
    for (int i = 1; i <= 70; i++) {
        if (cnt[i] == 0) {
            for (int m = 0; m < (1 << 19); m++)
                dp[i][m] = dp[i - 1][m];
        } else {
            for (int m = 0; m < (1 << 19); m++)
                dp[i][m] = ((dp[i - 1][m] + dp[i - 1][m ^ (mask[i])]) * poww[cnt[i] - 1]) % MOD;
        }
    }
    cout << dp[70][0] - 1;
    return 0;
}

