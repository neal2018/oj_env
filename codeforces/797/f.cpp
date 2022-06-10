#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll kmp(const string& txt, const string& pat) {
  if (txt.size() < pat.size()) kmp(pat, txt);
  int n = int(txt.size()), m = int(pat.size());
  vector<int> nex(m);  // nex[i]: LC prefix & suffix for pat[0..i]
  for (int i = 1, j = 0; i < m; i++) {
    while (j && pat[j] != pat[i]) j = nex[j - 1];
    if (pat[j] == pat[i]) j++;
    nex[i] = j;
  }
  for (int i = 0, j = 0; i < n; i++) {
    while (j && pat[j] != txt[i]) j = nex[j - 1];
    if (pat[j] == txt[i]) j++;
    if (j == m) {
      if (i - m + 1 != 0) return i - m + 1;
      j = nex[j - 1];
    }
  }
  throw;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    vector<int> p(n);
    for (auto& x : p) cin >> x, x--;
    vector<int> seen(n);
    ll res = 1;
    for (int i = 0; i < n; i++) {
      if (seen[i]) continue;
      vector<int> cur;
      while (seen[i] == 0) {
        cur.push_back(i);
        seen[i] = 1;
        i = p[i];
      }
      string t(cur.size(), '?');
      for (int j = 0; j < cur.size(); j++) {
        t[j] = s[cur[j]];
      }
      // cout << t << " " << need << "\n";
      res = lcm(res, kmp(t + t, t));
    }
    cout << res << "\n";
  }
}
