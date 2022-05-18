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
    vector<ll> a(n), b(n);
    for (auto &x : a) cin >> x, x--;
    for (auto &x : b) cin >> x, x--;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
      mp[a[i]] = i;
    }
    vector<ll> seen(n);
    set<int> st(a.begin(), a.end());
    vector<ll> per;
    ll res = 0;
    for (int i = 0; i < n; i++) {
      if (!seen[i]) {
        ll cur = i, cnt = 0;
        while (!seen[cur]) {
          seen[cur] = i + 1;
          cur = b[cur];
          cur = mp[cur];
          cnt++;
        }
        if (seen[cur] == i + 1 && cnt > 1) {
          per.push_back(cnt);
        }
      }
    }
    for (auto &x : per) {
      vector<ll> p;
      p.reserve(x);
      for (int i = 0; i < x; i++) {
        if (i % 2 == 0) {
          p.push_back(*st.rbegin());
          st.erase(--st.end());
        } else {
          p.push_back(*st.begin());
          st.erase(st.begin());
        }
        if ((x & 1) && i + 2 == x) break;
      }
      if (x & 1) {
        p.push_back(p.back() + 1);
      }
      ll cur = 0;
      for (int i = 0; i < x; i++) {
        cur += abs(p[i] - p[(i + 1) % x]);
      }
      res += cur;
    }
    cout << res << "\n";
  }
}
