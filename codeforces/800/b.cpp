#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> parent(n, -1), deg(n);
    for (auto i : views::iota(1, n)) {
      cin >> parent[i], parent[i]--, deg[parent[i]]++;
    }
    vector<pair<ll, ll>> a(n);
    for (auto& [x, y] : a) cin >> x >> y;
    int res = 0;
    vector<int> q, nq;
    for (auto i : views::iota(0, n)) {
      if (deg[i] == 0) q.push_back(i);
    }
    vector<ll> avail(n);
    for (; q.size(); swap(q, nq), nq.clear()) {
      for (auto& node : q) {
        if (avail[node] < a[node].first) res++, avail[node] = a[node].second;
        if (parent[node] != -1) {
          avail[parent[node]] += min(avail[node], a[node].second);
          if (--deg[parent[node]] == 0) nq.push_back(parent[node]);
        }
      }
    }
    cout << res << "\n";
  }
}
