#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector a(n, vector<int>(m));
  for (auto& r : a) {
    for (auto& x : r) cin >> x;
  }
  vector<vector<int>> g(m);
  vector<int> deg(m);
  vector<pair<int, int>> intervals;
  int extra = m;
  for (auto& r : a) {
    vector<int> order(m);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int x, int y) { return r[x] < r[y]; });
    int mini = -1, maxi = -1;
    for (int i = 0; i < m; i++) {
      if (r[order[i]] != 0) {
        if (mini == -1) mini = r[order[i]];
        maxi = r[order[i]];
      }
    }
    if (mini != -1) {
      intervals.push_back({mini, maxi});
    }
    int pre_node = -1;
    for (int i = 0, j = 0; i < m; i = j) {
      while (i < m && r[order[i]] == 0) i++;
      for (j = i; j < m && r[order[i]] == r[order[j]];) j++;
      if (pre_node != -1) {
        for (int k = i; k < j; k++) {
          g[order[k]].push_back(pre_node);
          deg[pre_node]++;
        }
      }
      if (j == m) break;
      pre_node = extra++;
      g.push_back({}), deg.push_back(0);
      for (int k = i; k < j; k++) {
        g[pre_node].push_back(order[k]);
        deg[order[k]]++;
      }
    }
  }
  vector<int> q, nq;
  for (int i = 0; i < m; i++) {
    if (deg[i] == 0) q.push_back(i);
  }
  for (; q.size(); swap(q, nq), nq.clear()) {
    for (auto& node : q) {
      for (auto& ne : g[node]) {
        if (--deg[ne] == 0) {
          nq.push_back(ne);
        }
      }
    }
  }
  if (accumulate(deg.begin(), deg.end(), 0ll) != 0) {
    cout << "No\n";
    return 0;
  }
  sort(intervals.begin(), intervals.end());
  for (int i = 1; i < intervals.size(); i++) {
    auto [s1, e1] = intervals[i - 1];
    auto [s2, e2] = intervals[i];
    if (s2 < e1) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
}
