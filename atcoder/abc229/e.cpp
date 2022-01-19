#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0, a, b; i < m; i++) {
    cin >> a >> b, a--, b--;
    g[a].push_back(b), g[b].push_back(a);
  }
  vector<ll> p(n);
  iota(p.begin(), p.end(), 0);
  function<ll(ll)> find = [&](ll x) { return x == p[x] ? x : (p[x] = find(p[x])); };
  auto merge = [&](ll x, ll y) { return p[find(x)] = p[find(y)]; };
  vector<ll> res(n);
  ll cur = 0;
  for (int i = n - 1; i >= 0; i--) {
    res[i] = cur;
    vector<ll> have;
    for (auto& ne : g[i]) {
      if (ne > i) have.push_back(find(ne));
    }
    sort(have.begin(), have.end());
    have.erase(unique(have.begin(), have.end()), have.end());
    cur -= have.size() - 1;
    for (auto& ne : g[i]) {
      if (ne > i) merge(ne, i);
    }
  }
  for (auto& x : res) cout << x << "\n";
}