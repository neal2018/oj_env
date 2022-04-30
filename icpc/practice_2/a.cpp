#include <bits/stdc++.h>
using ll = long long;
using namespace std;

constexpr ll MOD = 1e9 + 7;

ll power(ll a, ll b, ll res = 1) {
  for (; b; b /= 2, (a *= a) %= MOD) {
    if (b & 1) (res *= a) %= MOD;
  }
  return res;
}

const ll inv_2 = power(2, MOD - 2);

struct Node {
  ll sum = 0, sum2 = 0, sum_sq = 0, len = 0;
};

struct Tag {
  ll sum = 0, sum2 = 0;
};

Node pull(const Node& a, const Node& b) {
  return {(a.sum + b.sum) % MOD, (a.sum2 + b.sum2) % MOD, (a.sum_sq + b.sum_sq) % MOD,
          a.len + b.len};
}

Tag pull(const Tag& a, const Tag& b) { return {(a.sum + b.sum) % MOD, (a.sum2 + b.sum2) % MOD}; }

struct SegTree {
  ll n, h;
  vector<Node> t;
  vector<Tag> lazy;
  SegTree(ll _n) : n(_n), h((ll)log2(n)), t(2 * _n), lazy(2 * _n) {}
  void apply(ll x, const Tag& tag) {
    auto o = t[x];
    t[x] = {
        (o.sum + tag.sum * o.len) % MOD, (o.sum2 + tag.sum2 * o.len) % MOD,
        (o.sum_sq + 2 * tag.sum % MOD * o.sum % MOD + o.len * tag.sum % MOD * tag.sum % MOD) % MOD,
        o.len};
    lazy[x] = pull(lazy[x], tag);
  }
  void build(ll l) {
    for (l = (l + n) / 2; l > 0; l /= 2) {
      if (!(lazy[l].sum || lazy[l].sum2)) {
        t[l] = pull(t[l * 2], t[2 * l + 1]);
      }
    }
  }
  void push(ll l) {
    l += n;
    for (ll s = h; s > 0; s--) {
      ll i = l >> s;
      if (lazy[i].sum || lazy[i].sum2) {
        apply(2 * i, lazy[i]);
        apply(2 * i + 1, lazy[i]);
      }
      lazy[i] = {0, 0};
    }
  }
  void modify(ll l, ll r, const Tag& v) {
    push(l), push(r - 1);
    ll l0 = l, r0 = r;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) apply(l++, v);
      if (r & 1) apply(--r, v);
    }
    build(l0), build(r0 - 1);
  }
  Node query(ll l, ll r) {
    push(l), push(r - 1);
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
  ll n, q;
  cin >> n >> q;
  SegTree seg(n);
  for (ll i = 0; i < n; i++) seg.t[i + n] = {0, 0, 0, 1};
  for (ll i = n - 1; i > 0; i--) seg.t[i] = pull(seg.t[i * 2], seg.t[i * 2 + 1]);
  while (q--) {
    ll t;
    cin >> t;
    if (t == 1) {
      ll u, v;
      cin >> u >> v, u--;
      ll len = v - u;
      ll prob = power(len, MOD - 2);
      seg.modify(u, v, {prob, prob * prob % MOD});
    } else {
      auto node = seg.query(0, n);
      ll res = (node.sum + node.sum_sq - node.sum2 + MOD) % MOD;
      cout << res << "\n";
    }
  }
}