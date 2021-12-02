#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, T;
  cin >> T;
  auto f = [&]() {
    cin >> n;
    vector<int> b(n), p(n), dist(n, -1), w(n);
    int root = -1;
    for (int i = 0; i < n; i++) {
      cin >> b[i], b[i]--;
      if (b[i] == i) root = i;
    }
    for (auto& x : p) cin >> x, x--;
    if (p[0] != root) {
      cout << "-1\n";
      return;
    }
    dist[root] = 0;
    for (int i = 1; i < n; i++) {
      if (dist[b[p[i]]] == -1) {
        cout << "-1\n";
        return;
      }
      dist[p[i]] = dist[p[i - 1]] + 1;
      w[p[i]] = dist[p[i]] - dist[b[p[i]]];
    }
    for (auto& x : w) cout << x << " ";
    cout << '\n';
  };
  for (; T--;) {
    f();
  }
}