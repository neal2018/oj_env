#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<vector<int>> to(n);
    vector<vector<int>> from(n);
    vector<int> need(n, 1), deg(n);
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      for (int j = 0, x; j < k; j++) {
        cin >> x, x--;
        to[x].push_back(i);
        from[i].push_back(x);
        deg[i]++;
      }
    }
    vector<int> q, nq, seen(n);
    for (int i = 0; i < n; i++) {
      if (deg[i] == 0) q.push_back(i);
    }
    for (; q.size(); swap(q, nq), nq.clear()) {
      for (auto& node : q) {
        for (auto& ne : to[node]) {
          deg[ne]--;
          if (deg[ne] == 0) nq.push_back(ne);
        }
        for (auto& fa : from[node]) {
          need[node] = max(need[node], need[fa] + (fa > node));
        }
      }
    }
    if (accumulate(deg.begin(), deg.end(), 0ll) != 0) {
      cout << "-1\n";
    } else {
      cout << *max_element(need.begin(), need.end()) << "\n";
    }
  }
}