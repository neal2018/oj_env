#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    vector<int> ds;
    for (int i = 2, t = n; i <= t; i++) {
      if (t % i == 0) {
        ds.push_back(n / i);
        while (t % i == 0) t /= i;
      }
    }
    vector<vector<ll>> mp(ds.size());
    priority_queue<ll> pq, pq2;
    auto add = [&](int id, int x) {
      mp[id] = vector<ll>(x);
      for (int i = 0; i < n; i++) {
        mp[id][i % x] += a[i];
      }
      for (auto& t : mp[id]) pq.push(t * x);
    };
    for (int i = 0; i < ds.size(); i++) add(i, ds[i]);
    cout << pq.top() << '\n';
    while (q--) {
      int p, x;
      cin >> p >> x, p--;
      for (int i = 0; i < ds.size(); i++) {
        int k = ds[i], id = p % k;
        auto& v = mp[i];
        pq2.push(v[id] * k);
        v[id] += -a[p] + x;
        pq.push(v[id] * k);
      }
      a[p] = x;
      while (pq2.size() && pq.top() == pq2.top()) pq.pop(), pq2.pop();
      cout << pq.top() << "\n";
    }
  }
}
