#include <bits/stdc++.h>
using namespace std;

struct SAM {
  vector<unordered_map<int, int>> e = {{}};  // the labeled edges from node i
  vector<int> parent = {-1};                 // the parent of i
  vector<int> length = {0};                  // the length of the longest string
  int last = 0;                              // the index of node representing the whole string

  SAM(auto& s) {
    for (auto&& c : s) extend(c);
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

class Solution {
public:
  string longestDupSubstring(string s) {
    SAM sam(s);
    int sz = sam.e.size();
    vector<int> cnt(sz, 1);
    for (int i = sz - 1; i >= 1; i--) {
      cnt[sam.parent[i]] += cnt[i];
    }
    int p = -1;
    for (int i = 1; i < sz; i++) {
      if (p == -1 || cnt[i] > 1 && sam.length[i] > sam.length[p]) {
        p = i;
      }
    }
    if (p == -1) return "";
    string res;
    cout << sam.length[p] << endl;
    for (; p != 0; p = sam.parent[p]) {
      cout << p << " " << sam.parent[p] << endl;
      for (auto& [k, v] : sam.e[sam.parent[p]]) {
        if (v == p) res.push_back(k);
      }
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  string t = "abcd";
  s.longestDupSubstring(t);
  return 0;
}
