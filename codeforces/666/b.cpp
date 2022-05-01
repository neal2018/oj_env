#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    priority_queue<ll> pq(a.begin(), a.end());
    ll cnt = 0;
    ll pre = -1;
    while (pq.size()) {
      auto t = pq.top();
      pq.pop();
      if (pre == t) {
        if (pq.empty()) break;
        auto tt = pq.top();
        pq.pop();
        pq.push(t);
        t = tt;
      }
      pre = --t, cnt++;
      if (t) pq.push(t);
    }
    cout << ((cnt & 1) ? "T\n" : "HL\n");
  }
}
