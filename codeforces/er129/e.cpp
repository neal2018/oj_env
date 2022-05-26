#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

constexpr ll inf = 1e18;

vector<pair<pair<int, int>, pair<int, int>>> doors;

int dist(const pair<int, int> &a, const pair<int, int> &b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

pair<int, int> operator+(const pair<int, int> &a, const pair<int, int> &b) {
  return {a.first + b.first, a.second + b.second};
}

struct Node {
  array<array<ll, 2>, 2> a = {};
  int l = 0, r = 0, init = 0;
};

Node pull(const Node &a, const Node &b) {
  if (!a.init) return b;
  if (!b.init) return a;
  array<array<ll, 2>, 2> cross = {
      dist(doors[a.r].first + pair{1, 0}, doors[b.l].first) + 1,
      dist(doors[a.r].first + pair{1, 0}, doors[b.l].second) + 1,
      dist(doors[a.r].second + pair{0, 1}, doors[b.l].first) + 1,
      dist(doors[a.r].second + pair{0, 1}, doors[b.l].second) + 1,
  };
  array<array<ll, 2>, 2> cost = {inf, inf, inf, inf};
  for (int i : {0, 1}) {
    for (int j : {0, 1}) {
      for (int ii : {0, 1}) {
        for (int jj : {0, 1}) {
          cost[i][j] = min(cost[i][j], a.a[i][ii] + cross[ii][jj] + b.a[jj][j]);
        }
      }
    }
  }
  return {cost, a.l, b.r, 1};
}

struct SegTree {
  ll n;
  vector<Node> t;
  SegTree(ll _n) : n(_n), t(2 * n){};
  void modify(ll p, const Node &v) {
    t[p += n] = v;
    for (p /= 2; p; p /= 2) t[p] = pull(t[p * 2], t[p * 2 + 1]);
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
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  doors.resize(n - 1);
  for (auto &[p1, p2] : doors) {
    cin >> p1.first >> p1.second >> p2.first >> p2.second;
    p1.first--, p1.second--, p2.first--, p2.second--;
  }
  int sz = n - 1;
  SegTree seg(sz);
  for (int i = 0; i < sz; i++) seg.t[i + sz] = {{0, inf, inf, 0}, i, i, 1};
  for (int i = sz - 1; i; i--) seg.t[i] = pull(seg.t[i * 2], seg.t[i * 2 + 1]);
  ll q;
  cin >> q;
  while (q--) {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2, x1--, y1--, x2--, y2--;
    ll layer1 = max(x1, y1), layer2 = max(x2, y2);
    if (layer1 == layer2) {
      cout << dist({x1, y1}, {x2, y2}) << "\n";
      continue;
    }
    if (layer1 > layer2) swap(layer1, layer2), swap(x1, x2), swap(y1, y2);
    auto node = seg.query(layer1, layer2);
    ll res = inf;
    res = min(res, dist({x1, y1}, doors[layer1].first) + node.a[0][0] +
                       dist({x2, y2}, doors[layer2 - 1].first + pair{1, 0}) + 1);
    res = min(res, dist({x1, y1}, doors[layer1].first) + node.a[0][1] +
                       dist({x2, y2}, doors[layer2 - 1].second + pair{0, 1}) + 1);
    res = min(res, dist({x1, y1}, doors[layer1].second) + node.a[1][0] +
                       dist({x2, y2}, doors[layer2 - 1].first + pair{1, 0}) + 1);
    res = min(res, dist({x1, y1}, doors[layer1].second) + node.a[1][1] +
                       dist({x2, y2}, doors[layer2 - 1].second + pair{0, 1}) + 1);
    cout << res << "\n";
  }
}
