#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    auto solve = [&](vector<ll> a, int n, int k) -> bool {
      ll left_reach = k;   // consumed
      ll right_reach = k;  // consumed
      ll left_gain = a[k], right_gain = a[k];
      ll left_sum = a[k], right_sum = a[k];
      while (true) {
        ll stop = 0;
        ll id = left_reach, cur = left_sum + right_gain - a[k];
        while (id > 0 && cur >= 0) {
          if (a[id - 1] + cur < 0) break;
          cur += a[id - 1];
          left_sum += a[id - 1];
          if (left_sum > left_gain) left_gain = left_sum;
          id--;
        }
        if (id <= 0) return true;
        if (id == left_reach) stop++;
        left_reach = id;

        id = right_reach, cur = right_sum + left_gain - a[k];
        while (id < n - 1 && cur >= 0) {
          if (a[id + 1] + cur < 0) break;
          cur += a[id + 1];
          right_sum += a[id + 1];
          if (right_sum > right_gain) right_gain = right_sum;
          id++;
        }
        if (id >= n - 1) return true;
        if (id == right_reach) stop++;
        right_reach = id;
        if (stop == 2) return false;
      }
    };
    int n, k;
    cin >> n >> k, k--;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    if (solve(a, n, k) || solve(vector(a.rbegin(), a.rend()), n, n - k - 1)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
