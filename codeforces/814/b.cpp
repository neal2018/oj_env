#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    ll sum_f = 1, cnt = 1;
    vector<ll> f = {0, 1};
    while (sum_f < sum) {
      ll nex = f[cnt - 1] + f[cnt];
      cnt++, sum_f += nex;
      f.push_back(nex);
    }
    if (sum_f > sum) {
      cout << "NO\n";
      continue;
    }
    ll pre = -1;
    priority_queue<ll> pq(a.begin(), a.end());
    pq.push(0);
    while (f.size()) {
      ll c = pq.top();
      pq.pop();
      if (c == pre) {
        ll nc = pq.top();
        pq.pop(), pq.push(c), c = nc;
      }
      if (c < f.back()) break;
      c -= f.back(), f.pop_back();
      pre = c;
      pq.push(c);
    }
    cout << (f.size() ? "NO\n" : "YES\n");
  }
}
