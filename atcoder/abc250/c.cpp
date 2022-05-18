#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, q;
  cin >> n >> q;
  vector<ll> id(n), a(n);
  iota(id.begin(), id.end(), 0ll);
  iota(a.begin(), a.end(), 0ll);
  while (q--) {
    ll x;
    cin >> x, x--;
    if (id[x] == n - 1) {
      swap(a[id[x]], a[id[x] - 1]);
      swap(id[x], id[a[id[x]]]);
    } else {
      swap(a[id[x]], a[id[x] + 1]);
      swap(id[x], id[a[id[x]]]);
    }
  }
  for (auto& x : a) cout << x + 1 << " ";
  cout << "\n";
}
