#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1), pre(n + 1), from(n + 1), seen(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  set<int> st;
  for (int i = 1; i < n; i++) st.insert(i);
  vector<int> q = {n}, nq;
  int f = 1;
  for (; q.size() && f; swap(q, nq), nq.clear()) {
    for (auto node : q) {
      if (node - a[node] <= 0) {
        f = 0, from[0] = node;
        break;
      }
      while (true) {
        auto it = st.lower_bound(node - a[node]);
        if (it != st.end() && *it < node) {
          int i = *it;
          int ne = i + b[i];
          if (seen[ne] == 0) {
            from[ne] = node, pre[ne] = i;
            nq.push_back(ne);
            seen[ne] = 1;
          }
          st.erase(it);
        } else {
          break;
        }
      }
    }
  }
  if (f) {
    cout << -1 << '\n';
  } else {
    vector<int> res;
    for (int i = 0; i < n; i = from[i]) res.push_back(pre[i]);
    reverse(res.begin(), res.end());
    cout << res.size() << '\n';
    for (auto& x : res) cout << x << " ";
    cout << "\n";
  }
}