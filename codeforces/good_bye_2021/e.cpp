#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
  ll n;
  vector<int> t;
  SegTree(ll _n) : n(_n), t(2 * n) {}
  void modify(ll p, int v) {
    t[p += n] += v;
    for (p /= 2; p; p /= 2) t[p] = t[2 * p] + t[2 * p + 1];
  }
  int query(ll l, ll r) {
    int res = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) res += t[l++];
      if (r & 1) res += t[--r];
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  for (int tt = 0; tt < T; tt++) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    ll inf = 1e18, res = inf, cost = 0;
    SegTree seg(n + 1);
    vector<set<ll>> st(26);
    set<ll> removed;
    for (int i = 0; i < n; i++) st[s[i] - 'a'].insert(i);
    for (int i = 0; i < n; i++) {
      for (char j = 'a'; j < t[i]; j++) {
        if (st[j - 'a'].size()) {
          ll pos = *st[j - 'a'].begin(), add = seg.query(0, pos + 1);
          res = min(res, cost + pos - i + add);
        }
      }
      if (!st[t[i] - 'a'].size()) break;
      ll near = *st[t[i] - 'a'].begin(), add = seg.query(0, near + 1);
      cost += near + add - i;
      st[t[i] - 'a'].erase(near);
      seg.modify(0, 1), seg.modify(near + 1, -1);
    }
    cout << (res == inf ? -1 : res) << "\n";
  }
}
