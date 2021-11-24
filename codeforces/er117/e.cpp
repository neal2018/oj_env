#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  map<int, vector<int>> mp;
  for (int i = 0, m, k; i < n; i++) {
    cin >> m >> k;
    mp[m].push_back(k);
  }
  vector<pair<int, int>> ss;
  int maxi_sum = 0, maxi_cnt = 1, sz = (int)mp.size();
  for (int m = 1; m <= min(20, sz); m++) {
    ss.clear();
    for (auto& [k, v] : mp) {
      int sum = 0;
      for (auto& x : v) sum += min(x, m);
      ss.push_back({sum, k});
    }
    int sum = 0, cnt = m;
    ranges::sort(ss, greater());
    for (int i = 0; i < m; i++) {
      sum += ss[i].first;
    }
    if (sum * maxi_cnt > maxi_sum * cnt) {
      maxi_sum = sum, maxi_cnt = cnt;
    }
  }

  ss.clear();
  for (auto& [k, v] : mp) {
    int sum = accumulate(v.begin(), v.end(), 0);
    ss.push_back({sum, k});
  }
  ranges::sort(ss, greater());
  for (int sum = 0, cnt = 0; auto& [k, m] : ss) {
    sum += k, cnt++;
    if (cnt > 20 && sum * maxi_cnt > maxi_sum * cnt) {
      maxi_sum = sum, maxi_cnt = cnt;
    }
  }
  cout << maxi_cnt << '\n';
  ss.clear();
  for (auto& [k, v] : mp) {
    int sum = 0;
    for (auto& x : v) sum += min(x, maxi_cnt);
    ss.push_back({sum, k});
  }
  ranges::sort(ss, greater());
  for (int i = 0; i < maxi_cnt; i++) {
    cout << ss[i].second << " ";
  }
  cout << '\n';
}
