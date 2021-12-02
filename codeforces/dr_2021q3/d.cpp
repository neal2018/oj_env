#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
constexpr int N = 2 * 1e7;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, d, a, b, extra = 1;
  cin >> n >> d;
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  function<int(int)> find = [&](int x) { return p[x] == x ? x : (p[x] = find(p[x])); };
  auto merge = [&](int x, int y) { p[find(x)] = find(y); };
  while (d--) {
    cin >> a >> b, a--, b--;
    if (find(a) == find(b))
      extra++;
    else
      merge(a, b);
    map<ll, ll> mp;
    for (auto& x : p) mp[find(x)]++;
    vector<ll> vec;
    for (auto& [k, v] : mp) vec.push_back(v);
    ranges::sort(vec, greater());
    ll res = 0;
    for (auto x : ranges::take_view{vec, extra}) res += x;
    cout << res - 1 << '\n';
  }
}