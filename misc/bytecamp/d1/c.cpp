#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  ld s;
  cin >> n >> m >> s;
  ll s2 = ll(s * 2 + 0.01);

  auto print = [&](vector<pair<ll, ll>> &&a) {
    a.erase(unique(a.begin(), a.end()), a.end());
    while (a.back() == a[0]) a.pop_back();
    reverse(a.begin(), a.end());
    cout << a.size() << "\n";
    for (auto &[x, y] : a) {
      cout << x << " " << y << "\n";
    }
  };

  if (abs(s * 2 - s2) > 1e-9) {
    cout << "-1\n";
    return 0;
  }
  if (s2 > 2 * n * m) {
    cout << "-1\n";
    return 0;
  }
  // n*t>=s
  ll t = (s2 + 2 * n - 1) / (2 * n);
  ll subtract = (2 * n * t - s2) / 2;
  if (subtract == 0) {
    if (s2 & 1) {
      print({{0, 0}, {n - 1, 0}, {n, 1}, {n, t}, {0, t}});
    } else {
      print({{0, 0}, {n, 0}, {n, t}, {0, t}});
    }
  } else if (t == 1) {
    if (s2 & 1) {
      print({{0, 0}, {s2 / 2 + 1, 0}, {s2 / 2, 1}, {0, 1}});
    } else {
      print({{0, 0}, {s2 / 2, 0}, {s2 / 2, 1}, {0, 1}});
    }
  } else {
    if (s2 & 1) {
      print({{0, 0}, {n, 0}, {n, t - 1}, {n - 1, t}, {subtract, t}, {0, t - 2}});
    } else {
      print({{0, 0}, {n, 0}, {n, t}, {subtract, t}, {0, t - 2}});
    }
  }
}
