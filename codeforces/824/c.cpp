#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct UnionFind {
  vector<int> p;
  UnionFind(int n) : p(n) { iota(p.begin(), p.end(), 0); }
  int find(int x) { return x == p[x] ? x : (p[x] = find(p[x])); }
  void merge(int x, int y) { p[find(x)] = find(y); }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    auto uf = UnionFind(26);
    vector<int> nex(26, -1), pre(26, -1);
    string t;
    int linked = 0;
    for (int i = 0; i < n; i++) {
      int cur = s[i] - 'a';
      if (nex[cur] == -1) {
        for (int c = 0; c < 26; c++) {
          if (pre[c] != -1 || c == cur) continue;
          if (linked != 25) {
            if (uf.find(cur) == uf.find(c)) continue;
          }
          nex[cur] = c;
          pre[c] = cur;
          uf.merge(c, cur);
          linked++;
          break;
        }
      }
      t += char(nex[cur] + 'a');
    }
    cout << t << '\n';
  }
}
