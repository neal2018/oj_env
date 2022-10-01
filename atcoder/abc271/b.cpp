#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector a(n, vector<int>());
  for (auto& v : a) {
    int l;
    cin >> l;
    v.resize(l);
    for (auto& x : v) {
      cin >> x;
    }
  }
  while (q--) {
    int s, t;
    cin >> s >> t, s--, t--;
    cout << a[s][t] << "\n";
  }
}
