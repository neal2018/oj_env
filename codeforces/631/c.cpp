#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll h, g;
    cin >> h >> g;
    ll n = (1 << h) - 1;
    ll m = (1 << g) - 1;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> seen(2 * n, 1);
    for (int i = 1; i <= m; i++) seen[i] = 0;
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    sort(p.begin(), p.end(), [&](int x, int y) { return a[x] < a[y]; });
    ll total = 0;
    vector<int> marked(n + 1);
    for (auto i : p) {
      ll val = a[i];
      for (int j = i; j > 0; j /= 2) {
        if (j <= m && seen[j] == 0 && seen[2 * j] == 1 && seen[2 * j + 1] == 1) {
          seen[j] = 1, total += val;
          marked[i] = 1;
          break;
        }
      }
    }
    cout << total << "\n";
    for (ll i = n; i > 0; i--) {
      if (!marked[i]) cout << i << " ";
    }
    cout << "\n";
  }
}
