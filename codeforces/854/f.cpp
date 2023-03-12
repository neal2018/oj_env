#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, b, k1, k2;
    cin >> n >> b >> k1 >> k2;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    auto compress = a;
    compress.push_back(1e11);
    for (auto& x : a) compress.push_back(x / 2);
    sort(compress.begin(), compress.end());
    compress.erase(unique(compress.begin(), compress.end()), compress.end());
    ll res = accumulate(a.begin(), a.end(), 0ll);
    for (auto cut : compress) {
      ll cost = 0;
      priority_queue<array<ll, 2>> pq;
      for (auto& x : a) pq.push({x, 0});
      ll cur_k1 = k1, cur_k2 = k2;
      while (pq.size()) {
        auto [x, f] = pq.top();
        pq.pop();
        if (f == 1) {
          if (cur_k2 > 0) {
            x = max(x - b, 0ll);
            cur_k2--;
          }
          cost += x;
        } else if (f == 3) {
          cost += x;
        } else {
          if (x < cut && cur_k2 > 0 && f != 2) {
            x = max(x - b, 0ll);
            cur_k2--;
            pq.push({x, f | 2});
          } else if (cur_k1 > 0 && f != 1) {
            pq.push({(x + 1) / 2, 1});
            cur_k1--;
          } else {
            cost += x;
          }
        }
      }
      res = min(res, cost);
    }
    cout << res << "\n";
  }
}
