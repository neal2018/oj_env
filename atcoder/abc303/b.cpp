#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector a(m, vector<int>(n));
  for (auto& r : a) {
    for (auto& x : r) cin >> x, x--;
  }
  set<pair<int, int>> st;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) st.insert({i, j});
  }
  for (auto& r : a) {
    for (int i = 0; i < n - 1; i++) {
      auto t = minmax({r[i], r[i + 1]});
      st.erase(t);
    }
  }
  cout << st.size() << "\n";
}
