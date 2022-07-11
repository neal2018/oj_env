#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct GSAM {
  const int SZ = 10;
  vector<vector<int>> e = {vector<int>(SZ, -1)};
  vector<int> parent = {-1}, length = {0};
  int extend(int c, int p) {
    int r = 0, f = 1;
    if (e[p][c] == -1) {
      e.push_back(vector<int>(SZ, -1)), parent.push_back(0), length.push_back(length[p] + 1);
      f = 0, r = (int)e.size() - 1;
      for (; ~p && e[p][c] == -1; p = parent[p]) e[p][c] = r;
    }
    if (f || ~p) {
      int q = e[p][c];
      if (length[q] == length[p] + 1) {
        if (f) return q;
        parent[r] = q;
      } else {
        e.push_back(e[q]), parent.push_back(parent[q]), length.push_back(length[p] + 1);
        int qq = parent[q] = (int)e.size() - 1;
        for (; ~p && e[p][c] == q; p = parent[p]) e[p][c] = qq;
        if (f) return qq;
        parent[r] = qq;
      }
    }
    return r;
  }
  vector<int> get_order() {
    ll sz = e.size();
    vector<int> order(sz), c(sz + 1);
    for (int i = 1; i < sz; i++) c[length[i]]++;
    for (int i = 1; i < sz; i++) c[i] += c[i - 1];
    for (int i = 1; i < sz; i++) order[c[length[i]]--] = i;
    reverse(order.begin(), order.end());
    return order;
  }
};

vector<int> get_next(const string& pat) {
  int m = int(pat.size());
  vector<int> nex(m);  // nex[i]: LC prefix & suffix for pat[0..i]
  for (int i = 1, j = 0; i < m; i++) {
    while (j && pat[j] != pat[i]) j = nex[j - 1];
    if (pat[j] == pat[i]) j++;
    nex[i] = j;
  }
  return nex;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<int> last;
  int n;
  cin >> n;
  vector<string> a(n);
  for (auto& x : a) cin >> x;
  vector<vector<int>> kmps(n);
  for (int i = 0; i < n; i++) {
    string t(a[i].rbegin(), a[i].rend());
    kmps[i] = get_next(t);
    reverse(kmps[i].begin(), kmps[i].end());
  }
  GSAM gsam;
  for (auto& s : a) {
    int p = 0;
    for (auto& c : s) {
      p = gsam.extend(c - '0', p);
    }
    last.push_back(p);
  }
  ll sz = gsam.e.size();
  vector<int> cnt(sz);
  for (int i = 0; i < n; i++) {
    int p = last[i];
    int len = int(a[i].size()), largest = len;
    for (; p != 0; p = gsam.parent[p]) {
      cnt[p] += len - kmps[i][largest - len];
      if (gsam.parent[p] != -1) {
        len = gsam.length[gsam.parent[p]];
      }
    }
  }
  ll res = 0;
  for (auto& s : a) {
    ll p = 0, len = 0;
    for (auto& c : s) {
      p = gsam.e[p][c - '0'];
      len++;
      res += cnt[p];
    }
  }
  cout << res << "\n";
}
