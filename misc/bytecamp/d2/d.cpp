#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  map<int, vector<int>> mp_x, mp_y;
  map<ll, ll> x_sum, y_sum;
  vector<array<int, 3>> a(n);
  for (int i = 0; i < n; i++) {
    auto& [x, y, v] = a[i];
    cin >> x >> y >> v;
    x_sum[x] += v, y_sum[y] += v;
    mp_x[x].push_back(i), mp_y[y].push_back(i);
  }
  multiset<ll> ordered_x, ordered_y;
  for (auto& [k, v] : x_sum) ordered_x.insert(v);
  for (auto& [k, v] : y_sum) ordered_y.insert(v);
  ll res = max(*ordered_x.rbegin(), *ordered_y.rbegin());
  if (ordered_x.size() >= 3) {
    ll cur = *ordered_x.rbegin() + *(++ordered_x.rbegin()) + *(++ ++ordered_x.rbegin());
    res = max(res, cur);
  }
  if (ordered_y.size() >= 3) {
    ll cur = *ordered_y.rbegin() + *(++ordered_y.rbegin()) + *(++ ++ordered_y.rbegin());
    res = max(res, cur);
  }
  {
    auto update = [&](int p, int v) {
      ordered_y.erase(ordered_y.find(y_sum[p]));
      y_sum[p] += v;
      ordered_y.insert(y_sum[p]);
    };
    for (auto& [x, v] : mp_x) {
      ll cur = 0;
      for (auto& i : v) {
        update(a[i][1], -a[i][2]);
        cur += a[i][2];
      }
      cur += *ordered_y.rbegin();
      if (ordered_y.size() >= 2) {
        cur += *++ordered_y.rbegin();
      }
      res = max(res, cur);
      for (auto& i : v) update(a[i][1], a[i][2]);
    }
  }
  {
    auto update = [&](int p, int v) {
      ordered_x.erase(ordered_x.find(x_sum[p]));
      x_sum[p] += v;
      ordered_x.insert(x_sum[p]);
    };
    for (auto& [x, v] : mp_y) {
      ll cur = 0;
      for (auto& i : v) {
        update(a[i][0], -a[i][2]);
        cur += a[i][2];
      }
      cur += *ordered_x.rbegin();
      if (ordered_x.size() >= 2) {
        cur += *++ordered_x.rbegin();
      }
      res = max(res, cur);
      for (auto& i : v) update(a[i][0], a[i][2]);
    }
  }
  cout << res << "\n";
}
