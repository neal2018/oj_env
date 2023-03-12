#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, threshold;
  cin >> n >> threshold;
  vector<array<int, 4>> trans(n);
  vector<int> compress;
  for (auto& [x, y, z, w] : trans) {
    cin >> x >> y >> z >> w;
    compress.push_back(x);
    compress.push_back(y);
    compress.push_back(z);
  }
  sort(compress.begin(), compress.end());
  compress.erase(unique(compress.begin(), compress.end()), compress.end());

  map<int, int> mapping;
  int cnt = int(compress.size());
  for (int i = 0; i < cnt; i++) {
    mapping[compress[i]] = i;
  }

  vector<vector<int>> g(cnt);
  vector<int> deg(cnt), sum(cnt), a(cnt);
  for (auto& [x, y, z, w] : trans) {
    int mx = mapping[x];
    int my = mapping[y];
    int mz = mapping[z];
    deg[my]++, deg[mz]++;
    g[mx].push_back(my);
    g[mx].push_back(mz);
    a[mx] = w, a[mx] = w;
  }
  vector<int> q, nq;
  for (int i = 0; i < cnt; i++) {
    if (deg[i] == 0) q.push_back(i);
  }

  constexpr int MAX = 10010;
  vector<bitset<MAX>> has(cnt);
  for (; q.size(); swap(q, nq), nq.clear()) {
    for (auto& node : q) {
      has[node].set(node);
      for (auto& ne : g[node]) {
        has[ne] |= has[node];
        deg[ne]--;
        if (deg[ne] == 0) nq.push_back(ne);
      }
    }
  }
  int good_cnt = 0;
  for (int i = 0; i < n; i++) {
    auto& [x, y, z, w] = trans[i];
    int total = 0;
    for (int j = 0; j < n; j++) {
      if (has[compress[trans[i][0]]][compress[trans[j][0]]]) total += trans[j][3];
    }
    if (total >= threshold) {
      cout << x << " " << total << "\n";
      good_cnt++;
    }
  }
  cout << good_cnt << "\n";
}
