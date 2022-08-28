#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto get_next(string& pat) {
  int m = (int)pat.length();
  vector<int> nex(m), fail(m);
  for (int i = 1, j = 0; i < m; i++) {
    while (j && pat[j] != pat[i]) j = nex[j - 1];
    if (pat[j] == pat[i]) {
      j++;
    }
    nex[i] = (i < m - 1 && pat[i + 1] == pat[j]) ? fail[max(j - 1, 0)] : j;
  }
  return pair{nex, fail};
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  int q;
  cin >> s >> q;
  int n = int(s.size());
  auto&& [nex, fail] = get_next(s);
  nex.reserve(2e6);
  while (q--) {
    string t;
    cin >> t;
    int m = int(t.size());
    for (int i = 0; i < m; i++) nex.push_back(0);
    s += t;
    for (int i = n, j = nex[n - 1]; i < n + m; i++) {
      while (j && s[j] != s[i]) {
        j = (j < n ? fail[j - 1] : nex[j - 1]);
      }
      if (s[j] == s[i]) j++;
      nex[i] = j;
    }
    for (int i = n; i < n + m; i++) {
      cout << nex[i] << " ";
    }
    cout << "\n";
    while (m--) {
      s.pop_back();
      nex.pop_back();
    }
  }
}
