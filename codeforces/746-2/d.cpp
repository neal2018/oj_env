#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
int main() {
  // cin.tie(nullptr)->sync_with_stdio(false);
  int n, u, v, res;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  vector<int> dfn;
  function<void(int, int)> dfs = [&](int node, int fa) {
    dfn.push_back(node);
    for (auto& ne : g[node]) {
      if (ne == fa) continue;
      dfs(ne, node);
      if (dfn.back() != node) dfn.push_back(node);
    }
  };
  dfs(0, -1);
  auto ask = [&](int start, int end) {
    unordered_set<int> st;
    for (int i = start; i < end; i++) st.insert(dfn[i]);
    cout << "? " << st.size() << " ";
    for (auto& x : st) cout << x + 1 << " ";
    cout << endl;
    cin >> res;
    return res;
  };
  int maxi = ask(0, dfn.size()), left = 0, right = dfn.size();
  while (right - left > 2) {
    int mid = (left + right) / 2;
    if (ask(mid, right) == maxi)
      left = mid;
    else
      right = mid + 1;
  }
  cout << "! " << dfn[left] + 1 << " " << dfn[left + 1] + 1 << endl;
}