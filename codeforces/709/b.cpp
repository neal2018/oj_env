#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<int> a(n), nex(n), res, removed(n);
    for (auto& x : a) cin >> x;
    for (int i = 0; i < n; i++) nex[i] = (i + 1) % n;
    deque<int> q;
    for (int i = 0; i < n; i++)
      if (gcd(a[i], a[nex[i]]) == 1) q.push_back(i);
    while (q.size()) {
      int v = q.front();
      q.pop_front();
      if (removed[v]) continue;
      res.push_back(nex[v]);
      removed[nex[v]] = 1;
      nex[v] = nex[nex[v]];
      if (gcd(a[v], a[nex[v]]) == 1) q.push_back(v);
    }

    cout << res.size() << ' ';
    for (auto& x : res) cout << x + 1 << " ";
    cout << '\n';
  }
}