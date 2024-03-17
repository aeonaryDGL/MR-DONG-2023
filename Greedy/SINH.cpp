#include <bits/stdc++.h>
using namespace std;

#define Task "DATA"
#define ll long long
#define pb push_back

const int N = 1e6 + 6;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(Task".INP", "r")) {
        freopen(Task".INP", "w", stdout);
    }
    srand(time(NULL));
    cout << 40 << " " << rand() % 10000 << " " << rand() % 10000000 << "\n";
    for (int i = 1; i <= 40; i++) cout << rand() % 10000 << " ";
    return 0;
}

