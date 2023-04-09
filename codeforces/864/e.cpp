#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAX = 5 * 1000000 + 10;
vector<int> min_p(MAX + 1), phi(MAX + 1), primes;

struct Node {
  ll val = 0, need = 0, cnt = 1, init = 0;
};

Node pull(const Node &a, const Node &b) {
  if (!a.init) return b;
  if (!b.init) return a;
  auto va = a.val, vb = b.val;
  ll da = 0, db = 0;
  while (va != vb) {
    if (va > vb) {
      va = phi[va];
      da++;
    } else {
      vb = phi[vb];
      db++;
    }
  }
  return {va, a.need + da * a.cnt + b.need + db * b.cnt, a.cnt + b.cnt, 1};
}
struct SegTree {
  ll n;
  vector<Node> t;
  set<int> st;
  SegTree(ll _n) : n(_n), t(2 * n) {
    for (int i = 0; i < n; i++) st.insert(i);
  };
  void modify(ll p) {
    p += n;
    t[p].val = phi[t[p].val];
    for (p /= 2; p; p /= 2) t[p] = pull(t[p * 2], t[p * 2 + 1]);
  }
  void modify_range(ll l, ll r) {
    auto it = st.lower_bound(l);
    while (it != st.end() && *it < r) {
      modify(*it);
      if (t[(*it) + n].val == 1) {
        it = st.erase(it);
      } else {
        it++;
      }
    }
  }
  Node query(ll l, ll r) {
    Node left, right;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) left = pull(left, t[l++]);
      if (r & 1) right = pull(t[--r], right);
    }
    return pull(left, right);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  phi[1] = 1;
  for (int i = 2; i <= MAX; i++) {
    if (min_p[i] == 0) {
      min_p[i] = i;
      primes.push_back(i);
      phi[i] = i - 1;
    }
    for (auto p : primes) {
      if (i * p > MAX) break;
      min_p[i * p] = p;
      if (i % p == 0) {
        phi[i * p] = phi[i] * p;
        break;
      }
      phi[i * p] = phi[i] * phi[p];
    }
  }
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  SegTree seg(n);
  for (int i = 0; i < n; i++) seg.t[i + n] = {a[i], 0, 1, 1};
  for (int i = n - 1; i > 0; i--) seg.t[i] = pull(seg.t[i * 2], seg.t[i * 2 + 1]);
  while (q--) {
    int t, l, r;
    cin >> t >> l >> r, l--;
    if (t == 1) {
      seg.modify_range(l, r);
    } else {
      auto node = seg.query(l, r);
      cout << node.need << "\n";
    }
  }
}
