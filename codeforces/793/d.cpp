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
    string s;
    cin >> n >> s;
    ll one = count(s.begin(), s.end(), '1');
    ll first = -1, last = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        if (first == -1) first = i;
        last = i;
      }
    }
    if ((one & 1) || one == 0) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    vector<pair<ll, ll>> edges;
    ll cnt = 0, pre = first, parent = -1;
    for (ll i = first; i != (first - 1 + n) % n; i = (i + 1) % n) {
      if (s[i] == '1') {
        cnt++;
        if (cnt == 2) pre = i;
      }
      if (i == last) break;
      if (i != first) edges.push_back({parent, i});
      if (cnt == 3) {
        cnt = 1 + (s[i] == '1');
        parent = pre;
      } else {
        parent = i;
      }
    }
    for (ll i = (first - 1 + n) % n;;) {
      if (i == (first - 1 + n) % n) {
        edges.push_back({i, parent});
      } else {
        edges.push_back({i, (i + 1) % n});
      }
      if (i == last) break;
      i = (i - 1 + n) % n;
    }
    for (auto& [u, v] : edges) {
      cout << u + 1 << " " << v + 1 << "\n";
    }
  }
}
