#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (auto& x : a) cin >> x;
  vector pre(n + 1, vector<ll>(m + 1));
  for (auto i : views::iota(0, n)) {
    int cur = 0;
    for (auto j : views::iota(0, m)) {
      cur += a[i][j] == 'X';
      pre[i + 1][j + 1] = pre[i][j + 1] + cur;
    }
  }
  vector maxi(n, vector<ll>(m));
  for (auto i : views::iota(0, n)) {
    for (auto j : views::iota(0, m)) {
      int l = -1, r = min({i, n - i - 1, j, m - j - 1});
      auto check = [&](int mid) {
        int x1 = i - mid, y1 = j - mid;
        int x2 = i + mid, y2 = j + mid;
        ll area = pre[x2 + 1][y2 + 1] + pre[x1][y1] - pre[x1][y2 + 1] - pre[x2 + 1][y1];
        return area == (mid * 2 + 1) * (mid * 2 + 1);
      };
      while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid)) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      maxi[i][j] = l;
    }
  }
  vector<string> res(n, string(m, '.'));
  auto check = [&](ll mid) {
    vector b(n + 1, vector<ll>(m + 1));
    vector<string> candidate(n, string(m, '.'));
    for (auto i : views::iota(0, n)) {
      for (auto j : views::iota(0, m)) {
        if (maxi[i][j] >= mid) {
          ll x1 = i - mid, y1 = j - mid;
          ll x2 = i + mid, y2 = j + mid;
          b[x2 + 1][y2 + 1]++, b[x1][y1]++, b[x1][y2 + 1]--, b[x2 + 1][y1]--;
          candidate[i][j] = 'X';
        }
      }
    }
    vector now(n + 1, vector<ll>(m + 1));
    for (auto i : views::iota(0, n)) {
      ll cur = 0;
      for (auto j : views::iota(0, m)) {
        cur += b[i][j];
        now[i + 1][j + 1] = now[i][j + 1] + cur;
      }
    }
    for (auto i : views::iota(0, n)) {
      for (auto j : views::iota(0, m)) {
        if (a[i][j] == 'X' && now[i + 1][j + 1] == 0) return false;
      }
    }
    res = candidate;
    return true;
  };
  ll l = 0, r = min(n, m);
  while (l < r) {
    ll mid = (l + r + 1) / 2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  check(l);
  cout << l << "\n";
  for (auto& s : res) cout << s << "\n";
}
