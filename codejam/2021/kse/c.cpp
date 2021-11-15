#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll T, n, m;
  cin >> T;
  for (ll TT = 1; TT <= T; TT++) {
    cout << "Case #" << TT << ": ";
    cin >> n >> m;
    vector<string> a(n);
    for (auto& x : a) cin >> x;
    vector<int> uf(n * m);
    iota(uf.begin(), uf.end(), 0);
    function<int(int)> find = [&](int x) { return (x == uf[x]) ? x : (uf[x] = find(uf[x])); };
    auto merge = [&](int x, int y) {
      int px = find(x), py = find(y);
      if (px != py) {
        uf[px] = py;
      }
    };
    for (int i = 0; i < n; i++) {
      int pre = (a[i][0] == '#' ? -1 : 0);
      bool striking = (a[i][0] == '#' ? true : false);
      for (int j = 1; j < m; j++) {
        if (striking) {
          if (a[i][j] == '#') {
            continue;
          } else {
            pre = j;
            striking = false;
          }
        } else {
          if (a[i][j] == '#') {
            for (int pp = pre, jj = j - 1; pp <= jj; pp++, jj--) {
              merge(i * m + jj, i * m + pp);
            }
            striking = true;
          } else {
            continue;
          }
        }
      }
      if (!striking && pre != -1) {
        for (int pp = pre, jj = m - 1; pp <= jj; pp++, jj--) {
          merge(i * m + jj, i * m + pp);
        }
      }
    }
    for (int i = 0; i < m; i++) {
      int pre = (a[0][i] == '#' ? -1 : 0);
      bool striking = (a[0][i] == '#' ? true : false);
      for (int j = 1; j < n; j++) {
        if (striking) {
          if (a[j][i] == '#') {
            continue;
          } else {
            pre = j;
            striking = false;
          }
        } else {
          if (a[j][i] == '#') {
            for (int jj = j - 1, pp = pre; pp <= jj; pp++, jj--) {
              merge((jj)*m + i, pp * m + i);
            }
            striking = true;
          } else {
            continue;
          }
        }
      }
      if (!striking && pre != -1) {
        for (int jj = n - 1, pp = pre; pp <= jj; pp++, jj--) {
          merge((jj)*m + i, pp * m + i);
        }
      }
    }
    unordered_map<int, vector<pair<int, int>>> st;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        st[find(i * m + j)];
        st[find(i * m + j)].push_back({i, j});
      }
    }
    int cnt = 0;
    for (auto& [k, v] : st) {
      bool has = false;
      char fill = '.';
      for (auto& [i, j] : v) {
        if (a[i][j] != '.') {
          fill = a[i][j];
          has = true;
          break;
        }
      }
      if (has) {
        for (auto& [i, j] : v) {
          if (a[i][j] == '.') cnt++;
          a[i][j] = fill;
        }
      }
    }
    cout << cnt << endl;
    for (auto& ss : a) {
      cout << ss << endl;
    }
  }
}
