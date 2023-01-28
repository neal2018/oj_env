#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (auto& x : a) cin >> x;
  vector<string> b(m);
  for (auto& x : b) cin >> x;
  set<string> st{b.begin(), b.end()};
  int res = 0;
  for (auto& s : a) {
    if (st.count(s.substr(3, 6))) {
      res++;
    }
  }
  cout << res << "\n";
}