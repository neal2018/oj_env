#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<string> pos(k);
    for (auto i : views::iota(0, n)) {
      pos[i % k] += s[i];
    }
    int one = int(count(s.begin(), s.end(), '1')), res = one;
    for (auto& ss : pos) {
      int sz = int(ss.size());
      vector<int> v;
      for (int i = 0, j = 0; i < sz; i = j) {
        for (j = i; j < sz && ss[i] == ss[j];) j++;
        if (ss[i] == '0') {
          v.push_back(j - i);
        } else {
          v.push_back(i - j);
        }
      }
      int mini = 1e9, cur = 0;
      for (auto& x : v) {
        cur += x;
        mini = min(mini, cur);
        if (cur > 0) cur = 0;
      }
      res = min(res, mini + one);
    }
    cout << res << "\n";
  }
}
