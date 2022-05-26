#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  auto solve = [&](vector<ll>& a, vector<ll>& b) {
    sort(a.begin(), a.end()), sort(b.begin(), b.end());
    ll n = a.size(), m = b.size();
    vector<ll> matched(n), combo(m, 1);
    set<ll> st(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
      if (st.count(a[i])) matched[i] = 1;
    }
    ll p = 0, good = accumulate(matched.begin(), matched.end(), 0ll), res = good;
    for (ll i = 0; i < m; i++) {
      while (p < n && a[p] <= b[i]) good -= matched[p], p++;
      ll j = upper_bound(b.begin(), b.end(), b[i] - p) - b.begin();
      // [b[i]-p, b[i]]
      res = max(res, good + min(p, i - j + 1));
    }
    return res;
  };
  int T;
  cin >> T;
  while (T--) {
    ll n, m;
    cin >> n >> m;
    vector<ll> ap, an, bp, bn;
    for (int i = 0, x; i < n; i++) cin >> x, (x > 0 ? ap : an).push_back(abs(x));
    for (int i = 0, x; i < m; i++) cin >> x, (x > 0 ? bp : bn).push_back(abs(x));
    ll res = solve(ap, bp) + solve(an, bn);
    cout << res << "\n";
  }
}
