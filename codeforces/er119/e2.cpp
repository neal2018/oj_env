#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define ll long long
constexpr ll MOD = 998244353;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int q, MAX = 5e5 + 10;
  cin >> q;
  vector<pair<int, int>> op(q);
  for (int i = 0; i < q; i++) {
    int k, x, y = -1;
    cin >> k >> x;
    if (k == 2) cin >> y;
    op[i] = {x, y};
  }
  vector<int> p(MAX), res;
  iota(p.begin(), p.end(), 0);
  reverse(op.begin(), op.end());
  for (auto& [x, y] : op) {
    if (y == -1) {
      res.push_back(p[x]);
    } else {
      p[x] = p[y];
    }
  }
  reverse(res.begin(), res.end());
  for (auto& x : res) cout << x << " ";
  cout << '\n';
}
