#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto duval(string_view s) {
  int n = (int)s.size();
  vector<pair<string_view, int>> t;
  for (int i = 0; i < n;) {
    int j = i, k = i + 1, cnt = 0;
    for (; k < n && s[j] <= s[k]; j++, k++) {
      if (s[j] < s[k]) j = i - 1;
    }
    t.push_back({s.substr(i, k - j), 0});
    while (i <= j) cnt++, i += k - j;
    t.back().second = cnt;
  }
  return t;
}

auto minimal_represent(string s) {
  int n = (int)s.size(), res = 0;
  s += s;
  for (int i = 0; i < n;) {
    int j = i, k = i + 1;
    for (; k < 2 * n && s[j] <= s[k]; j++, k++) {
      if (s[j] < s[k]) j = i - 1;
    }
    res = i;
    while (i <= j) i += k - j;
  }
  return s.substr(res, n);
}

auto prefix(const string& t) {
  auto duval = [&](string_view s) {
    int n = (int)s.size(), res = 0;
    for (int i = 0; i < n;) {
      int j = i, k = i + 1;
      for (; k < n && s[j] <= s[k]; j++, k++) {
        if (s[j] < s[k]) j = i - 1;
      }
      res = i;
      while (i <= j) i += k - j;
    }
    return res;
  };
  int n = int(t.size());
  auto res = t, rt = string(t.rbegin(), t.rend());
  {
    auto last = duval(rt);
    auto cur = rt.substr(last) + t.substr(n - last);
    res = min(res, cur);
  }
  {
    rt += '{';
    auto last = duval(rt);
    auto cur = rt.substr(last, n - last) + t.substr(n - last);
    res = min(res, cur);
  }
  return res;
}

vector<int> z_function(string_view s) {
  int n = (int)s.size();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}

auto suffix(const string& s) {
  auto rs = string(s.rbegin(), s.rend());
  auto z = z_function(rs + '#' + s);
  int n = int(s.size()), res = n - 1;  // flip [res, n)
  for (int i = n - 2; i > 1; i--) {
    // flip [i, n)
    int part1 = z[n + 1 + i];
    if (part1 < res - i) {
      if (rs[part1] < s[i + part1]) res = i;
    } else {
      int part2 = z[part1];
      if (part2 < n - res) {
        if (rs[part1 + part2] < rs[part2]) res = i;
      }
    }
  }
  auto remain = s.substr(res);
  reverse(remain.begin(), remain.end());
  return s.substr(0, res) + remain;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  int k;
  cin >> s >> k;
  auto rs = string(s.rbegin(), s.rend());
  if (k == 1) {
    cout << min(s, rs) << "\n";
    return 0;
  }
  auto&& lyn = duval(rs);
  string res;
  for (int i = int(lyn.size()) - 1; i >= 0 && k > 2; i--) {
    for (int _ = lyn[i].second; _--;) res += lyn[i].first;
    k--;
    if (i > 0 && lyn[i - 1].first.size() == 1 && lyn[i].first.size() == 1) {
      k++;
    }
  }
  if (s.size() == res.size()) {
    cout << res << "\n";
    return 0;
  }
  auto t = string(s.begin() + res.size(), s.end());
  auto rt = string(t.rbegin(), t.rend());
  auto need = t;
  need = min(need, minimal_represent(rt));
  need = min(need, prefix(t));
  need = min(need, suffix(t));
  cout << res + need << '\n';
}
