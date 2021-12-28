#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct SAM {
  vector<unordered_map<int, int>> e = {{}};  // the labeled edges from node i
  vector<int> parent = {-1};                 // the parent of i
  vector<int> length = {0};                  // the length of the longest string
  int last = 0;  // the index of node representing the whole string
  SAM() {}
  template <class T>
  SAM(T& s) {
    for (auto&& c : s) {
      extend(c);
    }
  }
  void extend(int c) {
    e.emplace_back();  // append to end
    parent.push_back(0);
    length.push_back(length[last] + 1);
    int p = last;  // iterate the suffixes of old string
    int r = last = e.size() - 1;
    for (; p != -1 && !e[p].count(c); p = parent[p]) {
      e[p][c] = r;
    }
    if (p != -1) {  // meet an already linked
      int q = e[p][c];
      if (length[q] == length[p] + 1) {  // only jump one step
        parent[r] = q;
      } else {              // jump too far, need an intermediate
        e.push_back(e[q]);  // copy original q
        parent.push_back(parent[q]);
        length.push_back(length[p] + 1);
        int qq = parent[q] = parent[r] = e.size() - 1;
        for (; p != -1 && e[p][c] == q; p = parent[p]) {
          e[p][c] = qq;
        }
      }
    }
  }
};
int main() {
  ll x, y;
  cin >> x >> y;
  string sx = bitset<64>(x).to_string();
  sx.erase(0, sx.find_first_not_of('0'));
  string sy = bitset<64>(y).to_string();
  sy.erase(0, sy.find_first_not_of('0'));
  vector<int> pre(sy.size() + 1);
  for (ll i = 0; i < sy.size(); i++) pre[i + 1] = pre[i] + sy[i] - '0';
  vector<int> suf(sy.size() + 1);
  for (ll i = (ll)sy.size() - 1; i >= 0; i--) suf[i] = suf[i + 1] + sy[i] - '0';
  string sx2 = sx;
  while (sx2.back() == '0') sx2.pop_back();
  string sx3 = sx2;
  reverse(sx3.begin(), sx3.end());
  string sx4 = sx + '1';
  string sx5 = sx4;
  reverse(sx5.begin(), sx5.end());
  for (auto& s : {sx, sx2, sx3, sx4, sx5}) {
    for (int t = 0; t + s.size() <= sy.size(); t++) {
      int f = 1;
      for (int i = 0; i < s.size() && f; i++)
        if (s[i] != sy[i + t]) f = 0;
      if (f && pre[t] == t && suf[t + s.size()] == (ll)sy.size() - (t + s.size())) {
        if (t + s.size() == sy.size() && s.back() == '0' && t != 0) continue;
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
}