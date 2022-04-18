#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

constexpr int SZ = 26;
struct GSAM {
  vector<vector<int>> e = {vector<int>(SZ)};  // the labeled edges from node i
  vector<int> parent = {-1};                  // the parent of i
  vector<int> length = {0};                   // the length of the longest string

  GSAM(int n) { e.reserve(2 * n), parent.reserve(2 * n), length.reserve(2 * n); };
  int extend(int c, int p) {  // character, last
    bool f = true;            // if already exist
    int r = 0;                // potential new node
    if (!e[p][c]) {           // only extend when not exist
      f = false;
      e.push_back(vector<int>(SZ));
      parent.push_back(0);
      length.push_back(length[p] + 1);
      r = (int)e.size() - 1;
      for (; ~p && !e[p][c]; p = parent[p]) e[p][c] = r;  // update parents
    }
    if (f || ~p) {
      int q = e[p][c];
      if (length[q] == length[p] + 1) {
        if (f) return q;
        parent[r] = q;
      } else {
        e.push_back(e[q]);
        parent.push_back(parent[q]);
        length.push_back(length[p] + 1);
        int qq = parent[q] = (int)e.size() - 1;
        for (; ~p && e[p][c] == q; p = parent[p]) e[p][c] = qq;
        if (f) return qq;
        parent[r] = qq;
      }
    }
    return r;
  }
};

constexpr ll MAX = 4e6 + 10;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  GSAM gsam(MAX);
  vector<vector<int>> g(n);
  g.reserve(MAX);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int p = 0;
    for (auto& c : s) {
      p = gsam.extend(c - 'a', p);
      g.resize(gsam.e.size());
      g[p].push_back(i);
    }
  }
  ll sz = gsam.e.size();
  vector<int> c(sz + 1);
  vector<int> order(sz);
  for (int i = 1; i < sz; i++) c[gsam.length[i]]++;
  for (int i = 1; i < sz; i++) c[i] += c[i - 1];
  for (int i = 1; i < sz; i++) order[c[gsam.length[i]]--] = i;
  reverse(order.begin(), order.end());
  vector<ll> p(n);
  iota(p.begin(), p.end(), 0);
  function<ll(ll)> find = [&](ll x) { return x == p[x] ? x : (p[x] = find(p[x])); };
  auto merge = [&](ll x, ll y) { p[find(x)] = find(y); };
  ll res = 0;
  for (auto& node : order) {
    if (node == 0) continue;
    int first = -1;
    for (auto& id : g[node]) {
      if (first == -1) {
        first = id;
      } else {
        if (find(id) != find(first)) {
          merge(id, first);
          res += gsam.length[node];
        }
      }
    }
    if (first != -1 && gsam.parent[node] > 0) {
      g[gsam.parent[node]].push_back(first);
    }
  }
  cout << res << "\n";
}
