#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  auto f = [&]() {
    ll n;
    cin >> n;
    ll left_cost, right_cost, all_cost;
    pair<ll, ll> left, right, all;
    for (int i = 0, x, y, c; i < n; i++) {
      cin >> x >> y >> c;
      auto check = [&]() {
        if (left == right) return min(left_cost, right_cost);
        if (left.first >= right.first && left.second <= right.second) return right_cost;
        if (right.first >= left.first && right.second <= left.second) return left_cost;
        return left_cost + right_cost;
      };
      if (i == 0) {
        left = {x, y}, right = {x, y}, left_cost = c, right_cost = c;
        all = {x, y}, all_cost = c;
      } else {
        if (x < left.first || (x == left.first && left_cost > c)) {
          left = {x, y}, left_cost = c;
        }
        if (y > right.second || (y == right.second && right_cost > c)) {
          right = {x, y}, right_cost = c;
        }
        if (x == left.first && y == right.second) {
          if (all != pair<ll, ll>{x, y} || all_cost > c) {
            all = {x, y}, all_cost = c;
          }
        }
      }
      ll cost = check();
      if (all.first <= left.first && all.second >= right.second) cost = min(cost, all_cost);
      cout << cost << '\n';
    }
  };
  while (T--) f();
}