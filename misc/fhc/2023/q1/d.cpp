
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll TIME = 1000'000'006;
constexpr ll MOD = 1000'000'007;

struct Info {
  ll mini = MOD, maxi = 0, mini_id = -1, maxi_id = -1;
};

struct Node {
  array<Info, 2> info;
};

auto get_node(ll val, ll index) {
  auto res = Node();
  res.info[0] = {val, val, index, index};
  return res;
}

struct Tag {
  ll v = 0;
};

Node pull(const Node& a, const Node& b) {
  auto res = a;
  for (int i : {0, 1}) {
    if (b.info[i].mini < a.info[i].mini ||
        (b.info[i].mini == a.info[i].mini && b.info[i].mini_id < a.info[i].mini_id)) {
      res.info[i].mini = b.info[i].mini;
      res.info[i].mini_id = b.info[i].mini_id;
    }
    if (b.info[i].maxi > a.info[i].maxi ||
        (b.info[i].maxi == a.info[i].maxi && b.info[i].maxi_id < a.info[i].maxi_id)) {
      res.info[i].maxi = b.info[i].maxi;
      res.info[i].maxi_id = b.info[i].maxi_id;
    }
  }
  return res;
}

Tag pull(const Tag& a, const Tag& b) { return {a.v ^ b.v}; }

Node apply_tag(const Node& a, const Tag& b) {
  auto res = a;
  if (b.v) {
    swap(res.info[0], res.info[1]);
  }
  return res;
}

struct SegTree {
  ll n, h;
  vector<Node> t;
  vector<Tag> lazy;
  SegTree(ll _n) : n(_n), h((ll)log2(n)), t(2 * _n), lazy(2 * _n) {}
  void apply(ll x, const Tag& tag) {
    t[x] = apply_tag(t[x], tag);
    lazy[x] = pull(lazy[x], tag);
  }
  void build(ll l) {
    for (l = (l + n) / 2; l > 0; l /= 2) {
      if (!lazy[l].v) t[l] = pull(t[l * 2], t[2 * l + 1]);
    }
  }
  void push(ll l) {
    for (ll s = h; s > 0; s--) {
      ll i = (l + n) >> s;
      if (lazy[i].v) apply(2 * i, lazy[i]), apply(2 * i + 1, lazy[i]);
      lazy[i] = Tag();
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
  cout << fixed << setprecision(10);
  int T;
  cin >> T;

  for (int test_case_no = 1; test_case_no <= T; test_case_no++) {
    int n;
    cin >> n;
    ll all_res = 0;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    SegTree seg(n);

    for (int i = 0; i < n; i++) seg.t[i + n] = get_node(a[i], i);
    for (int i = n - 1; i >= 0; i--) seg.t[i] = pull(seg.t[2 * i], seg.t[2 * i + 1]);

    int q;
    cin >> q;
    while (q--) {
      int l, r;
      cin >> l >> r, l--;
      seg.modify(l, r, {1});
      auto node = seg.query(0, n);
      ll val = 0, res = -1;
      if (node.info[0].maxi_id != -1) {
        if (node.info[0].maxi > val || (node.info[0].maxi == val && node.info[0].maxi_id < res)) {
          val = node.info[0].maxi;
          res = node.info[0].maxi_id;
        }
      }
      if (node.info[1].mini_id != -1) {
        if (MOD - node.info[1].mini > val ||
            (MOD - node.info[1].mini == val && node.info[1].mini_id < res)) {
          val = MOD - node.info[1].mini;
          res = node.info[1].mini_id;
        }
      }
      assert(res >= 0);
      all_res += res + 1;
    }
    cout << "Case #" << test_case_no << ": " << all_res << "\n";
  }
}
