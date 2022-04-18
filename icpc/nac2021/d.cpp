#include <bits/stdc++.h>
using namespace std;

#define FOR(x, n) for (int x = 0; x < n; x++)
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
const char nl = '\n';

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);

  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (ll& z : a) cin >> z;

  sort(all(a));

  ll dp[60][60][60];
  memset(dp, 0, sizeof(dp));
  ll ans = 0;

  for (int i = 1; i < n; i++) {
    for (int one = 0; one < i; one++) {
      dp[i][one][2] = 1;
    }
    for (int one = 0; one < i; one++) {
      for (int two = 0; two < one; two++) {
        if (a[one] + a[two] >= a[i]) {
          for (int k = 2; k < 59; k++) {
            dp[i][one][k] += dp[one][two][k - 1];
            if (k == m) ans += dp[one][two][k - 1];
          }
        }
      }
    }
  }

  cout << ans << nl;
}