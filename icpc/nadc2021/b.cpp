#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int SZ = 26;
constexpr int MAX = 2e5 + 10;
int e[MAX][SZ];  // vector is faster than unordered_map
int fail[MAX], ed[MAX];
struct AC_automaton {
  int cnt = 0;
  void insert(string& s, int t) {
    int p = 0;
    for (auto cc : s) {
      int c = cc - 'a';
      if (!e[p][c]) {
        e[p][c] = ++cnt;
      }
      p = e[p][c];
    }
    ed[p] = t + 1;
  }

  void build() {
    queue<int> q;
    for (int i = 0; i < SZ; i++)
      if (e[0][i]) q.push(e[0][i]);
    while (!q.empty()) {
      int p = q.front();
      q.pop();
      for (int i = 0; i < SZ; i++) {
        if (e[p][i]) {
          fail[e[p][i]] = e[fail[p]][i];
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
  cin >> s;
  int n;
  cin >> n;
  string t[n];
  int g[n];
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> g[i];
  }
  auto b = vector<string>(t, t + n);
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  int sz = (int)b.size();
  vector<int> match[sz];
  AC_automaton ac;
  for (int i = 0; i < sz; i++) {
    ac.insert(b[i], i);
  }
  ac.build();
  int cur = 0;
  for (int i = 0; i < s.size(); i++) {
    cur = e[cur][s[i] - 'a'];
    if (cur != 0) {
      int p = cur, pre = cur;
      while (p != 0) {
        if (ed[p] > 0) {
          match[ed[p] - 1].push_back(i);
        } else {
          fail[pre] = fail[p];
        }
        pre = p, p = fail[p];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    ll tt = lower_bound(b.begin(), b.end(), t[i]) - b.begin();
    if (g[i] > match[tt].size()) {
      cout << "-1\n";
    } else {
      cout << match[tt][g[i] - 1] - (int)t[i].size() + 2 << "\n";
    }
  }
}