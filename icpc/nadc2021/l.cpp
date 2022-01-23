#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> g(n);
  for (auto& x : g) cin >> x;
  if (n < m) {
    vector<string> gg(m);
    for (int i = 0; i < m; i++) {
      string s;
      for (int j = 0; j < n; j++) s += g[j][i];
      gg[i] = s;
    }
    g = gg;
    swap(n, m);
  }
}