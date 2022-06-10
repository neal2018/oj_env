#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector a(n, vector<int>(n));
  for (auto& r : a) {
    for (auto& x : r) cin >> x;
  }
  vector<int> salary(n), parent(n), marked(n);
  for (int i = 0; i < n; i++) salary[i] = a[i][i];
  function<void(vector<int>, int)> solve = [&](vector<int> cur, int fa) {
    if (cur.size() == 1) {
      parent[cur[0]] = fa;
      return;
    }
    int maxi = -1;
    for (auto i : cur) {
      for (auto j : cur) maxi = max(maxi, a[i][j]);
    }
    parent.push_back(fa), salary.push_back(maxi);
    fa = int(parent.size()) - 1;

    for (auto i : cur) {
      if (marked[i]) continue;
      vector<int> candidate;
      for (auto j : cur) {
        if (a[i][j] != maxi) candidate.push_back(j);
      }
      solve(candidate, fa);
      for (auto& x : candidate) marked[x] = 1;
    }
  };
  vector<int> v(n);
  iota(v.begin(), v.end(), 0);
  solve(v, -1);
  cout << salary.size() << "\n";
  for (auto& x : salary) cout << x << " ";
  cout << "\n";
  cout << n + 1 << "\n";
  for (auto i : views::iota(0, int(parent.size()))) {
    if (parent[i] != -1) cout << i + 1 << " " << parent[i] + 1 << "\n";
  }
}
