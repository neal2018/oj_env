#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 1e9;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  auto check = [=](int g, vector<int> a) {
    if (g > *max_element(a.begin(), a.end())) return inf;
    for (auto& v : a) v /= g;
    int res = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] != 1) {
        for (auto& v : {2, 3}) {
          while (a[i] != 1 && a[i] % v == 0) {
            a[i] /= v, res++;
          }
        }
        if (a[i] != 1) {
          return inf;
        }
      }
    }
    return res;
  };
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  int g = a[0], res = inf;
  for (auto& v : a) g = gcd(g, v);
  res = min(res, check(g, a));
  cout << (res == inf ? -1 : res) << "\n";
}
