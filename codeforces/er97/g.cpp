#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr int SZ = 26;
struct GSAM {
  vector<vector<int>> e = {vector<int>(SZ)};  // the labeled edges from node i
  vector<int> parent = {-1};                  // the parent of i
  vector<int> length = {0};                   // the length of the longest string

  GSAM(int n) { e.reserve(2 * n), parent.reserve(2 * n), length.reserve(2 * n); };
  int extend(int c, int p) {  // character, last
    bool f = true;            // if already exist
    int r = 0;                // potential new node
    if (!e[p][c]) {           // only extend when not exist
      f = false;
      e.push_back(vector<int>(SZ));
      parent.push_back(0);
      length.push_back(length[p] + 1);
      r = (int)e.size() - 1;
      for (; ~p && !e[p][c]; p = parent[p]) e[p][c] = r;  // update parents
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
        int qq = parent[q] = (int)e.size() - 1;
        for (; ~p && e[p][c] == q; p = parent[p]) e[p][c] = qq;
        if (f) return qq;
        parent[r] = qq;
      }
    }
    return r;
  }
};

constexpr ll MAX = 4e5;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, q;
  cin >> n >> q;
  GSAM gsam(MAX);
  vector<ll> ends(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int p = 0;
    for (auto& c : s) {
      p = gsam.extend(c - 'a', p);
    }
    ends[i] = p;
  }
  vector<multiset<ll>> st(gsam.e.size());
  for (auto& p : ends) {
    st[p].insert(0);
  }
  ll total = gsam.e.size(), len = 0;
  vector<ll> val(n);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      ll i, x;
      cin >> i >> x, i--;
      st[ends[i]].erase(st[ends[i]].find(val[i]));
      val[i] = x;
      st[ends[i]].insert(val[i]);
    } else {
      string s;
      cin >> s;
      int p = 0;
      for (auto& c : s) {
        p = gsam.extend(c - 'a', p);
      }
      ll res = -1, cur = 0;
      for (auto& c : s) {
        ll i = c - 'a';
        while (cur != 0 && gsam.e[cur][i] == 0) cur = gsam.parent[cur], len = gsam.length[cur];
        cur = gsam.e[cur][i], len++;
        ll to_search = len == gsam.length[cur] ? cur : gsam.parent[cur];
        if (to_search < total && to_search > 0 && st[to_search].size()) {
          res = max(res, *st[to_search].rbegin());
        }
      }
      cout << res << "\n";
    }
  }
}
