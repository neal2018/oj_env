#include <bits/stdc++.h>
using namespace std;

struct ACAM {
  const int SZ = 26;
  vector<vector<int>> e = {vector<int>(SZ)};
  vector<int> fail = {0}, end = {0}, fast = {0};  // closest end

  int insert(string& s) {
    int p = 0;
    for (auto c : s) {
      c -= 'a';
      if (!e[p][c]) {
        e.emplace_back(SZ), fail.emplace_back();
        end.emplace_back(), fast.emplace_back();
        e[p][c] = int(e.size()) - 1;
      }
      p = e[p][c];
    }
    end[p]++;
    return p;
  }

  void build() {
    queue<int> q;
    for (int i = 0; i < SZ; i++) {
      if (e[0][i]) q.push(e[0][i]);
    }
    while (!q.empty()) {
      int p = q.front();
      q.pop();
      fast[p] = end[p] ? p : fast[fail[p]];
      for (int i = 0; i < SZ; i++) {
        if (e[p][i]) {
          fail[e[p][i]] = e[fail[p]][i];
          end[e[p][i]] += end[fail[e[p][i]]];
          q.push(e[p][i]);
        } else {
          e[p][i] = e[fail[p]][i];
        }
      }
    }
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  int q;
  cin >> s >> q;
  ACAM ac;
  while (q--) {
    string t;
    cin >> t;
    ac.insert(t);
  }
  ac.build();
  int res = 0, p = 0;
  for (auto& c : s) {
    p = ac.e[p][c - 'a'];
    if (ac.end[p]) {
      res++, p = 0;
    }
  }
  cout << res << "\n";
}
