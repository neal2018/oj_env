#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n;
  cin >> n;
  ll sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  n += 2;
  vector<string> a(n);
  a[0] = a[n - 1] = string(n, '#');
  for (int i = 0; i < n - 2; i++) {
    string s;
    cin >> s;
    a[i + 1] = string(1, '#') + s + '#';
  }
  map<ll, set<ll>> dia, anti;
  map<ll, set<ll>> block_dia, block_anti;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == '#') {
        block_dia[i + j].insert(i - j);
        block_anti[i - j].insert(i + j);
      } else {
        dia[i + j].insert(i - j);
        anti[i - j].insert(i + j);
      }
    }
  }
  vector<vector<int>> seen(n, vector<int>(n));
  vector<pair<int, int>> q{{sx, sy}}, nq;
  seen[sx][sy] = 1;
  for (int step = 0; q.size(); swap(q, nq), nq.clear(), step++) {
    for (auto& [x, y] : q) {
      if (x == tx && y == ty) {
        cout << step << "\n";
        return 0;
      }
      {
        auto pre_block = *--block_dia[x + y].upper_bound(x - y);
        auto after_block = *block_dia[x + y].upper_bound(x - y);
        auto it = dia[x + y].lower_bound(pre_block);
        for (; it != dia[x + y].end() && *it < after_block;) {
          nq.push_back({((x + y) + *it) / 2, ((x + y) - *it) / 2});
          anti[*it].erase(x + y);
          it = dia[x + y].erase(it);
        }
      }
      {
        auto pre_block = *--block_anti[x - y].upper_bound(x + y);
        auto after_block = *block_anti[x - y].upper_bound(x + y);
        auto it = anti[x - y].lower_bound(pre_block);
        for (; it != anti[x - y].end() && *it < after_block;) {
          nq.push_back({((x - y) + *it) / 2, (*it - (x - y)) / 2});
          dia[*it].erase(x - y);
          it = anti[x - y].erase(it);
        }
      }
    }
  }
  cout << -1 << "\n";
}
