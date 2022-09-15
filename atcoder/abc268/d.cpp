#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  int total = 0;
  for (auto& x : a) cin >> x, total += int(x.size());
  set<string> st;
  for (int i = 0; i < m; i++) {
    string t;
    cin >> t;
    st.insert(t);
  }
  string s;
  function<void(int)> dfs = [&](int i) {
    if (i == n) {
      if (s.size() >= 3 && st.count(s) == 0) {
        cout << s << "\n";
        exit(0);
      }
      return;
    }
    int need = 0;
    for (int j = i; j < n; j++) {
      need += int(a[j].size());
    }
    int origin = int(s.size());
    for (int j = i; j < n; j++) {
      swap(a[i], a[j]);
      s += a[i];
      if (i != n - 1) {
        int remain = n - 1 - i;
        for (int pos = 1; need + remain - 1 + pos + origin <= 16; pos++) {
          s += '_';
          dfs(i + 1);
        }
      } else {
        dfs(i + 1);
      }
      while (s.size() > origin) s.pop_back();
      swap(a[j], a[i]);
    }
  };
  dfs(0);
  cout << "-1\n";
}
