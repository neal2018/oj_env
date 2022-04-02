#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

void solveSudoku(vector<vector<vector<char>>>& board) {
  int n = 9;
  vector<int> rows(n), cols(n);
  auto check = [&](int i, int j, int x) {
    return rows[i] & x || cols[j] & x ;
  };
  auto add = [&](int i, int j, int x) { rows[i] |= x, cols[j] |= x; };
  auto remove = [&](int i, int j, int x) { rows[i] &= ~x, cols[j] &= ~x; };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (auto& t : board[i][j]) {
        if (t == '-') continue;
        int x = 1 << (t - '1');
        rows[i] |= x, cols[j] |= x;
      }
    }
  }
  bool solved = false;
  function<void(int, int)> dfs = [&](int i, int j) {
    if (i == n) {
      solved = true;
      return;
    }
    if (j == n) return dfs(i + 1, 0);
    if (board[i][j].size() == 1) {
      auto& t = board[i][j][0];
      if (t != '-') return dfs(i, j + 1);
      for (int c = 0; c < 9; c++) {
        int x = 1 << c;
        if (check(i, j, x)) continue;
        t = c + '1';
        add(i, j, x);
        dfs(i, j + 1);
        if (solved) return;
        remove(i, j, x);
        t = '-';
      }
    } else {
      auto &t = board[i][j][0], &t2 = board[i][j][1];
      if (t != '-' && t2 != '-') return dfs(i, j + 1);
      if (t == '-' && t2 == '-') {
        for (int c = 0; c < 9; c++) {
          for (int cc = c + 1; cc < 9; cc++) {
            int x = 1 << c, xx = 1 << cc;
            if (check(i, j, x) || check(i, j, xx)) continue;
            t = c + '1', t2 = cc + '1';
            add(i, j, x);
            add(i, j, xx);
            dfs(i, j + 1);
            if (solved) return;
            remove(i, j, xx);
            remove(i, j, x);
            t = '-', t2 = '-';
          }
        }
      } else if (t == '-') {
        int maxi = t2 - '1';
        for (int c = 0; c < maxi; c++) {
          int x = 1 << c;
          if (check(i, j, x)) continue;
          t = c + '1';
          add(i, j, x);
          dfs(i, j + 1);
          if (solved) return;
          remove(i, j, x);
          t = '-';
        }
      } else {
        int mini = t - '1';
        for (int c = mini + 1; c < 9; c++) {
          int x = 1 << c;
          if (check(i, j, x)) continue;
          t2 = c + '1';
          add(i, j, x);
          dfs(i, j + 1);
          if (solved) return;
          remove(i, j, x);
          t2 = '-';
        }
      }
    }
  };
  dfs(0, 0);
}

constexpr ll MOD = 100007;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<vector<vector<char>>> a(6, vector<vector<char>>(6));
  string s;
  for (auto& r : a) {
    for (auto& v : r) {
      cin >> s;
      if (s.size() == 1) {
        v = {s[0]};
      } else {
        v = {s[0], s[2]};
      }
    }
  }
  solveSudoku(a);
  for (auto& r : a) {
    for (auto& v : r) {
      if (v.size() == 1) {
        cout << v[0] << " ";
      } else {
        cout << v[0] << "/" << v[1] << " ";
      }
    }
    cout << "\n";
  }
}
