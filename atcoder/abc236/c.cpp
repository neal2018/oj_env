#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<string> a(n), b(m);
  for (auto& x : a) cin >> x;
  for (auto& x : b) cin >> x;
  set<string> st(b.begin(), b.end());
  for (auto& x : a) {
    if (st.count(x)) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}
