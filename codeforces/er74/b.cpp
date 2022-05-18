#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, r;
    cin >> n >> r;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    ll p = 0;
    while (true) {
      if (a.empty() || a.back() <= p) break;
      auto t = a.back();
      while (a.size() && a.back() == t) {
        a.pop_back();
      }
      p += r;
    }
    cout << p / r << "\n";
  }
}
