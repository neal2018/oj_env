#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

struct AC_automaton {
  int sz = 26;
  vector<vector<int>> e = {vector<int>(sz)};  // vector is faster than unordered_map
  vector<int> fail = {0}, end = {0};
  vector<int> fast = {0};  // closest end

  int insert(string& s) {
    int p = 0;
    for (auto c : s) {
      c -= 'a';
      if (!e[p][c]) {
        e.emplace_back(sz);
        fail.emplace_back();
        end.emplace_back();
        fast.emplace_back();
        e[p][c] = (int)e.size() - 1;
      }
      p = e[p][c];
    }
    end[p] += 1;
    return p;
  }

  void build() {
    queue<int> q;
    for (int i = 0; i < sz; i++)
      if (e[0][i]) q.push(e[0][i]);
    while (!q.empty()) {
      int p = q.front();
      q.pop();
      fast[p] = end[p] ? p : fast[fail[p]];
      for (int i = 0; i < sz; i++) {
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
  ll n, q;
  cin >> n >> q;
  AC_automaton ac;
  vector<ll> ends(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int p = 0;
    p = ac.insert(s);
    ends[i] = p;
  }
  ac.build();
  vector<multiset<ll>> st(ac.e.size());
  for (auto& p : ends) st[p].insert(0);
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
      ll res = -1, cur = 0;
      for (auto& c : s) {
        ll i = c - 'a';
        cur = ac.e[cur][i];
        for (ll qq = ac.fast[cur]; qq; qq = ac.fast[ac.fail[qq]]) {
          if (st[qq].size()) {
            res = max(res, *st[qq].rbegin());
          }
        }
      }
      cout << res << "\n";
    }
  }
}
