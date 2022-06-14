#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct SegTree {
  ll n;
  vector<int> t;
  SegTree(ll _n) : n(_n), t(2 * n) {}
  void modify(ll p, int v) {
    t[p += n] = v;
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
  cout << fixed << setprecision(20);
  auto ask1 = [&](ll x) {
    char c;
    cout << "? 1 " << x + 1 << endl;
    cin >> c;
    return c;
  };
  auto ask2 = [&](ll l, ll r) {
    // [l, r]
    int c;
    cout << "? 2 " << l + 1 << " " << r + 1 << endl;
    cin >> c;
    return c;
  };
  ll n;
  cin >> n;
  SegTree seg(n);
  string s(n, '?');
  s[0] = ask1(0);
  int cur = 1;
  vector<int> pos{0};
  vector<int> freq(n, 1);
  seg.modify(0, 1);
  for (int i : views::iota(1, n)) {
    int cnt = ask2(0, i);
    if (cnt > cur) {
      pos.push_back(i);
      s[i] = ask1(i);
      cur = cnt;
      seg.modify(i, 1);
    }
    freq[i] = cnt;
  }
  for (int i : views::iota(1, n)) {
    if (s[i] == '?') {
      auto r = --upper_bound(pos.begin(), pos.end(), i) - pos.begin();
      ll l = 0;
      while (l < r) {
        ll mid = (l + r + 1) / 2;
        if (ask2(pos[mid], i) > seg.query(pos[mid], i)) {
          r = mid - 1;
        } else {
          l = mid;
        }
      }
      s[i] = s[pos[l]];
      seg.modify(pos[l], 0);
      pos.erase(pos.begin() + l);
      seg.modify(i, 1);
      pos.push_back(i);
      sort(pos.begin(), pos.end());
    }
  }
  cout << "! " << s << endl;
}
