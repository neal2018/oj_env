#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

struct GSAM {
  vector<map<int, int>> e = {{}};  // the labeled edges from node i
  vector<int> parent = {-1};       // the parent of i
  vector<int> length = {0};        // the length of the longest string
  vector<int> cnt = {0};
  int extend(int c, int p) {  // character, last
    bool f = true;            // if already exist
    int r = 0;                // potential new node
    if (!e[p].count(c)) {     // only extend when not exist
      f = false;
      e.emplace_back();
      parent.push_back(0);
      length.push_back(length[p] + 1);
      cnt.push_back(1);
      r = int(e.size()) - 1;
      for (; ~p && !e[p].count(c); p = parent[p]) {
        e[p][c] = r;  // update parents
      }
    }
    if (f || ~p) {
      int q = e[p][c];
      if (length[q] == length[p] + 1) {
        if (f) return q;
        parent[r] = q;
      } else {
        e.push_back(e[q]);
        parent.push_back(parent[q]);
        length.push_back(length[p] + 1);
        cnt.push_back(0);
        int qq = parent[q] = int(e.size()) - 1;
        for (; ~p && e[p][c] == q; p = parent[p]) {
          e[p][c] = qq;
        }
        if (f) return qq;
        parent[r] = qq;
      }
    }
    return r;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  GSAM sam;
  int p = 0;
  for (int i = n - 1; i >= 0; i--) {
    p = sam.extend(a[i], p);
  }
  int total = int(sam.e.size());
  vector<int> mini(total, INT_MAX);
  vector<int> c(total + 1);
  vector<int> aa(total);
  // need to iterate nodes from LONG to SHORT in order to update PARENT
  for (int i = 0; i < total; i++) c[sam.length[i]]++;
  for (int i = 0; i < total; i++) c[i + 1] += c[i];
  for (int i = 0; i < total; i++) aa[--c[sam.length[i]]] = i;
  for (int i = total - 1; i > 0; i--) {
    sam.cnt[sam.parent[aa[i]]] += sam.cnt[aa[i]];
  }
  int cur = 0;
  vector<int> res(n);
  for (int i = 0; i < n; i++) {
    if (sam.e[cur].count(a[i]) == 0) {
      break;
    } else {
      cur = sam.e[cur][a[i]];
      res[i] = sam.cnt[cur];
    }
  }
  for (auto& x : res) cout << x << " ";
  cout << "\n";
}
