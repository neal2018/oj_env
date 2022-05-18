#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    string s, t;
    cin >> s >> t;
    ll n = s.size(), m = t.size();
    vector<vector<int>> a(26);
    for (int i = 0; i < n; i++) {
      a[s[i] - 'A'].push_back(i);
    }
    for (auto &x : a) reverse(x.begin(), x.end());
    ll pre = n, f = 1;
    for (ll i = m - 1; i >= 0 && f; i--) {
      auto &v = a[t[i] - 'A'];
      int j = 0;
      for (j = 0; j < v.size(); j++) {
        if (v[j] != -1) break;
      }
      if (j == v.size() || v[j] > pre) {
        f = 0;
      } else {
        pre = v[j];
        v[j] = -1;
      }
    }
    // for (auto &x : a) {
    //   for (auto &xx : x) cout << xx << " ";
    //   cout << "\n";
    // }
    cout << (f ? "YES\n" : "NO\n");
  }
}