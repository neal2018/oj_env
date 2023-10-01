#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  auto rotate = [&](vector<string> a) {
    int n = int(a.size()), m = int(a[0].size());
    vector<string> res(m, string(n, '.'));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        res[j][n - i - 1] = a[i][j];
      }
    }
    return res;
  };
  auto get = [&] {
    vector<string> a(4);
    for (auto& x : a) cin >> x;
    while (a[0] == "....") a.erase(a.begin());
    while (a.back() == "....") a.pop_back();
    a = rotate(a);
    while (a[0] == string(a[0].size(), '.')) a.erase(a.begin());
    while (a.back() == string(a[0].size(), '.')) a.pop_back();
    return a;
  };

  vector<vector<string>> can;
  for (int i = 0; i < 3; i++) {
    can.push_back(get());
  }

  auto check = [&](vector<string>& cur_a, vector<string>& cur_b, vector<string>& cur_c) {
    for (int ai = 0; ai + cur_a.size() <= 4; ai++) {
      for (int aj = 0; aj + cur_a[0].size() <= 4; aj++) {
        for (int bi = 0; bi + cur_b.size() <= 4; bi++) {
          for (int bj = 0; bj + cur_b[0].size() <= 4; bj++) {
            for (int ci = 0; ci + cur_c.size() <= 4; ci++) {
              for (int cj = 0; cj + cur_c[0].size() <= 4; cj++) {
                vector<vector<int>> res(4, vector<int>(4));
                auto fill = [&](vector<string>& a, int ii, int jj) {
                  for (int i = 0; i < a.size(); i++) {
                    for (int j = 0; j < a[0].size(); j++) {
                      if (a[i][j] == '#') {
                        res[i + ii][j + jj]++;
                      }
                    }
                  }
                };
                fill(cur_a, ai, aj);
                fill(cur_b, bi, bj);
                fill(cur_c, ci, cj);
                if ([&] {
                      for (auto& x : res) {
                        if (x != vector{1, 1, 1, 1}) return false;
                      }
                      return true;
                    }()) {
                  return true;
                }
              }
            }
          }
        }
      }
    }
    return false;
  };

  [&] {
    auto cur_a = can[0];
    for (int i = 0; i < 4; i++) {
      auto cur_b = can[1];
      for (int j = 0; j < 4; j++) {
        auto cur_c = can[2];
        for (int k = 0; k < 4; k++) {
          if (check(cur_a, cur_b, cur_c)) {
            cout << "Yes\n";
            return;
          }
          cur_c = rotate(cur_c);
        }
        cur_b = rotate(cur_b);
      }
      cur_a = rotate(cur_a);
    }
    cout << "No\n";
  }();
}
