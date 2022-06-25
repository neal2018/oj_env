#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector a(n, vector<ll>(m));
    set<ll> st;
    for (auto& r : a) {
      for (auto& x : r) cin >> x, st.insert(x);
    }
    int f = 0;
    for (auto& v : st) {
      for (auto i : views::iota(0, n)) {
        for (auto j : views::iota(0, m)) {
          if (a[i][j] == v && (i + j) % 2 == f) a[i][j] += 1;
        }
      }
      f = !f;
    }
    for (auto& r : a) {
      for (auto& x : r) cout << x << " ";
      cout << "\n";
    }
  }
}
