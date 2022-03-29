#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  map<string, int> is_pre, is_nex;
  map<string, set<string>> prev, nex;
  set<string> all;
  vector<string> tmp;
  vector<vector<string>> res;
  int pre_comma = 0;
  for (string s, pre; cin >> s;) {
    int has_period = 0, has_comma = 0;
    if (s.back() == '.') {
      has_period = 1, s = s.substr(0, (int)s.size() - 1);
    }
    if (s.back() == ',') {
      has_comma = 1, s = s.substr(0, (int)s.size() - 1);
    }
    tmp.push_back(s);
    all.insert(s);
    if (pre_comma) is_pre[s] = 1;
    if (has_comma) is_nex[s] = 1;
    if (pre != "") {
      prev[s].insert(pre);
      nex[pre].insert(s);
    }
    if (has_period) {
      res.push_back(tmp), tmp.clear();
      pre_comma = 0, pre = "";
    } else {
      pre_comma = has_comma, pre = s;
    }
  }
  set<pair<string, int>> seen;
  function<void(const string& s, int)> dfs = [&](const string& s, int is_check_pre) {
    if (is_check_pre && !is_pre[s]) return;
    if (!is_check_pre && !is_nex[s]) return;
    if (seen.count({s, is_check_pre})) return;
    seen.insert({s, is_check_pre});
    if (is_check_pre) {
      for (auto& t : prev[s]) is_nex[t] = 1, dfs(t, 0);
    } else {
      for (auto& t : nex[s]) is_pre[t] = 1, dfs(t, 1);
    }
  };
  for (auto& s : all) dfs(s, 0), dfs(s, 1);
  for (auto& sen : res) {
    ll sz = sen.size();
    for (int i = 0; i < sz - 1; i++) {
      cout << sen[i];
      if (is_nex[sen[i]]) cout << ",";
      cout << " ";
    }
    cout << sen.back() << ". ";
  }
}
