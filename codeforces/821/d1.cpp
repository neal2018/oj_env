#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, c1, c2;
    string s, s2;
    cin >> n >> c1 >> c2 >> s >> s2;
    vector<int> a;
    for (int i = 0; i < n; i++) {
      if (s[i] != s2[i]) a.push_back(i);
    }
    if (a.size() % 2) {
      cout << "-1\n";
      continue;
    }
    ll start = 0, res = 0, end = int(a.size());
    auto cost = [&](ll i, ll j) {
      if (i > j) swap(i, j);
      if (i + 1 == j) {
        return min(2 * c2, c1);
      } else {
        return c2;
      }
    };
    if (a.size() % 4 == 2) {
      res += cost(a[0], a.back()), start++, end--;
    }
    for (ll t = start; t + 2 < end; t += 4) {
      res += cost(a[t], a[t + 2]);
    }
    for (ll t = start + 1; t + 2 < end; t += 4) {
      res += cost(a[t], a[t + 2]);
    }
    cout << res << "\n";
  }
}
