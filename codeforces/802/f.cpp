#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector a(2, vector<int>(n));
  vector b(2, vector<int>(n));
  int sum_a = 0, sum_b = 0;
  for (auto& r : a) {
    for (auto& x : r) cin >> x, sum_a += x;
  }
  for (auto& r : b) {
    for (auto& x : r) cin >> x, sum_b += x;
  }
  if (sum_a != sum_b) {
    cout << "-1\n";
  }
  ll res = 0;
  for (int i = 0; i < n; i++) {
    if (pair{a[0][i], a[1][i]} == pair{b[0][i], b[1][i]}) {
      continue;
    }
    if (a[0][i] + a[1][i] == b[0][i] + b[1][i]) {
      res++;
    } else {
      res += 2;
    }
  }
  cout << res << "\n";
}
