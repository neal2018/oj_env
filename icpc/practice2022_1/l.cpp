#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  map<string, int> id;
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    id[s] = i;
  }
  vector<vector<int>> a(n, vector<int>(m));
  for (auto &r : a) {
    for (auto &x : r) cin >> x;
  }
  string s, tt;
  getline(cin, s);
  getline(cin, s);
  string t = "SELECT COUNT(*) FROM Table GROUP BY ";
  s = s.substr(t.size());
  s = s.substr(0, s.size() - 1);
  stringstream ss(s);
  vector<int> need;
  while (getline(ss, tt, ',')) {
    need.push_back(id[tt]);
  }
  sort(need.begin(), need.end());
  map<vector<int>, int> cnt;
  for (auto &r : a) {
    vector<int> cur;
    for (auto i : need) {
      cur.push_back(r[i]);
    }
    cnt[cur]++;
  }
  cout << cnt.size() << "\n";
  for (auto &[k, v] : cnt) cout << v << " ";
  cout << "\n";
}