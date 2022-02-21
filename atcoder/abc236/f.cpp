#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

struct Basis {
  const int SZ = 64;
  vector<ll> a = vector<ll>(SZ);
  Basis(int sz) : SZ(sz), a(sz) {}
  bool insert(ll x) {
    for (int i = SZ - 1; i >= 0; i--) {
      if (x >> i) {
        if (!a[i]) {
          a[i] = x;
          return true;
        } else {
          x ^= a[i];
        }
      }
    }
    return false;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  ll total = (1 << n) - 1;
  vector<ll> a(total);
  for (auto& x : a) cin >> x;
  vector<ll> p(total);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](ll x, ll y) { return a[x] < a[y]; });
  Basis bs(n);
  ll res = 0;
  for (auto& i : p) {
    if (bs.insert(i + 1)) {
      res += a[i];
    }
  }
  cout << res << "\n";
}
