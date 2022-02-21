#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<int> p(n + 1);
  iota(p.begin(), p.end(), 0);
  function<int(int)> find = [&](int x) { return p[x] == x ? x : (p[x] = find(p[x])); };
  auto merge = [&](int x, int y) { p[find(x)] = find(y); };
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    merge(l, r);
  }
  if (find(0) == find(n)) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
