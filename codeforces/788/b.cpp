#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll k;
    cin >> k;
    vector<char> a(k);
    for (auto& x : a) cin >> x;
    set<char> st(a.begin(), a.end());
    set<ll> p;
    for (int i = 0; i < n; i++) {
      if (st.count(s[i])) {
        p.insert(i);
      }
    }
    set<ll> deleted;
    vector<ll> pre(n + 1);
    iota(pre.begin(), pre.end(), 0);
    function<ll(ll)> find = [&](ll x) { return x == pre[x] ? x : (pre[x] = find(pre[x])); };
    auto merge = [&](ll x, ll y) { pre[find(x)] = find(y); };
    ll cnt = 0;
    while (p.size()) {
      auto cc = p;
      set<ll> to_del;
      ll f = 0;
      for (auto& i : p) {
        if (i != 0 && find(i - 1) != n) {
          ll t = find(i - 1);
          deleted.insert(t);
          to_del.insert(t);
          cc.erase(t);
          f = 1;
        } else {
          cc.erase(i);
        }
      }
      for (auto& i : to_del) {
        if (i == 0) {
          merge(i, n);
        } else {
          merge(i, i - 1);
        }
      }
      p = cc;
      if (f) cnt++;
    }
    cout << cnt << "\n";
  }
}
