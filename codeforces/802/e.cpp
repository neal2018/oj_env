#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector a(n, vector<int>(m));
  for (auto& r : a) {
    for (auto& x : r) cin >> x, x--;
  }
  vector<pair<int, int>> bad, d4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  auto check = [&](int i, int j) {
    if (a[i][j] == 0) return true;
    for (auto& [di, dj] : d4) {
      int ii = i + di, jj = j + dj;
      if (0 <= ii && ii < n && 0 <= jj && jj < m) {
        if (a[ii][jj] < a[i][j]) return true;
      }
    }
    return false;
  };
  for (auto i : views::iota(0, n)) {
    for (auto j : views::iota(0, m)) {
      if (!check(i, j)) bad.push_back({i, j});
    }
  }
  if (!bad.size()) {
    cout << "0\n";
    return 0;
  }
  if (bad.size() > 5) {
    cout << "2\n";
    return 0;
  }
  auto possible = [&] {
    set st(bad.begin(), bad.end());
    for (auto& [i, j] : bad) {
      for (auto& [di, dj] : d4) {
        int ii = i + di, jj = j + dj;
        if (0 <= ii && ii < n && 0 <= jj && jj < m) {
          st.insert({ii, jj});
        }
      }
    }
    return vector(st.begin(), st.end());
  }();
  set<pair<pair<int, int>, pair<int, int>>> st;
  for (auto x1 : views::iota(0, n)) {
    for (auto y1 : views::iota(0, m)) {
      for (auto& [x2, y2] : possible) {
        swap(a[x1][y1], a[x2][y2]);
        if ([&] {
              if (!check(x1, y1) || !check(x2, y2)) return false;
              for (auto& [i, j] : bad) {
                if (!check(i, j)) return false;
              }
              for (auto& [i, j] : {pair{x1, y1}, pair{x2, y2}}) {
                for (auto& [di, dj] : d4) {
                  int ii = i + di, jj = j + dj;
                  if (0 <= ii && ii < n && 0 <= jj && jj < m) {
                    if (!check(ii, jj)) return false;
                  }
                }
              }
              return true;
            }()) {
          st.insert(minmax(pair{x1, y1}, pair{x2, y2}));
        }
        swap(a[x1][y1], a[x2][y2]);
      }
    }
  }
  if (st.size() == 0) {
    cout << "2\n";
  } else {
    cout << "1 " << st.size() << "\n";
  }
}
