#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 1e9;

struct SegTree {
  ll n;
  vector<int> t;
  SegTree(ll _n) : n(_n), t(2 * n, inf) {}
  void modify(ll p, int v) {
    t[p += n] = v;
    for (p /= 2; p; p /= 2) t[p] = min(t[2 * p], t[2 * p + 1]);
  }
  int query(ll l, ll r) {
    int res = inf;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) res = min(res, t[l++]);
      if (r & 1) res = min(res, t[--r]);
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, len = 0;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x, len = max(len, x), x--;
    vector<set<int>> st(len, set{inf});
    SegTree seg(len);
    int cur = 0;
    ll res = 0;
    auto add = [&](ll p, ll v) {
      res += p - v;
      st[p].insert(v);
      seg.modify(p, *(st[p].begin()));
    };
    auto remove = [&](ll p, ll v) {
      res -= p - v;
      st[p].erase(v);
      seg.modify(p, *(st[p].begin()));
    };
    function<void(int)> f = [&](int x) {
      if (x >= cur) {
        add(x, cur), cur++;
      } else if (x < cur) {
        auto check = [&](int mid) {
          auto val = seg.query(mid, len);
          return val <= x;
        };
        int l = x, r = len;
        while (l < r) {
          int mid = (l + r + 1) / 2;
          if (check(mid)) {
            l = mid;
          } else {
            r = mid - 1;
          }
        }
        if (l > x) {
          auto go = *(st[l].begin());
          remove(l, go);
          add(x, go);
          f(l);
        }
      }
    };

    vector<ll> a_bf;
    auto bf = [&] {
      ll maxi = 0;
      vector<int> freq(n);
      for (auto& x : a_bf) maxi = max(maxi, x + 1), freq[x]++;
      ll res = 0;
      for (int i = 0, j = 0; i < maxi; i++) {
        j = max(j, i);
        while (j < maxi && freq[j] == 0) j++;
        if (j == maxi) break;
        freq[i]++, freq[j]--, res += j - i;
      }
      return res;
    };

    for (auto& x : a) {
      f(x);
      // a_bf.push_back(x);
      cout << res << " ";
      // cout << bf() << " ";
      // assert(res == bf());
    }
    cout << "\n";
  }
}
