#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> p(n), cnt(n);
  iota(p.begin(), p.end(), 0);
  function<int(int)> find = [&](int x) { return p[x] == x ? x : (p[x] = find(p[x])); };
  auto merge = [&](int x, int y) { p[find(x)] = find(y); };
  for (int i = 0, a, b; i < m; i++) {
    cin >> a >> b, a--, b--;
    if (find(a) == find(b) || cnt[a] >= 2 || cnt[b] >= 2) {
      cout << "No\n";
      return 0;
    }
    cnt[a]++, cnt[b]++;
    merge(a, b);
  }
  cout << "Yes\n";
}