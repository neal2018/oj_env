#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> deg(n), p(n, -1);
    for (int i = 1; i < n; i++) cin >> p[i], p[i]--, deg[p[i]]++;
    auto check = [&](int mid) {
      auto degree = deg;
      vector<int> q, nq;
      vector<int> cur(n, 1);
      for (int i = 0; i < n; i++) {
        if (degree[i] == 0) q.push_back(i);
      }
      int res = 0;
      for (; q.size(); swap(q, nq), nq.clear()) {
        for (auto& node : q) {
          if (node && p[node]) {
            if (cur[node] >= mid) {
              res++;
            } else {
              cur[p[node]] = max(cur[p[node]], cur[node] + 1);
            }
            degree[p[node]]--;
            if (degree[p[node]] == 0) {
              nq.push_back(p[node]);
            }
          }
        }
      }
      return res <= k;
    };
    int l = 1, r = n;
    while (l < r) {
      int mid = (l + r) / 2;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    cout << r << "\n";
  }
}
