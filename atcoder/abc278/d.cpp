#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  int q;
  cin >> q;
  vector<ll> version(n);
  ll cur_ver = 0;
  ll global = 0;
  auto update = [&](ll i, ll x) {
    if (version[i] != cur_ver) {
      a[i] = global + x;
      version[i] = cur_ver;
    } else {
      a[i] += x;
    }
  };
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      ll x;
      cin >> x;
      global = x;
      cur_ver++;
    } else if (t == 2) {
      ll i, x;
      cin >> i >> x, i--;
      update(i, x);
    } else if (t == 3) {
      ll i;
      cin >> i, i--;
      update(i, 0);
      cout << a[i] << "\n";
    }
  }
}
