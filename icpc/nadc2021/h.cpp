#include <bits/stdc++.h>
using namespace std;

template <class T>
struct SAM {
  vector<map<int, int>> e = {{}};  // the labeled edges from node i
  vector<int> parent = {-1};       // the parent of i
  vector<int> length = {0};        // the length of the longest string
  int last = 0;                    // the index of node representing the whole string

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
  int n;
  cin >> n;
  vector<string> paths(n);
  for (auto& x : paths) cin >> x;
  if (n == 1) {
    cout << paths[0].size() << endl;
    return 0;
  }
  sort(paths.begin(), paths.end(), [](auto& a, auto& b) { return a.size() < b.size(); });
  auto sam = SAM(paths[0]);
  int total = sam.e.size();
  vector<int> mini(total, INT_MAX);
  int n_p = paths.size();
  vector<int> c(total + 1);
  vector<int> a(total);
  // need to iterate nodes from LONG to SHORT in order to update PARENT
  for (int i = 0; i < total; i++) c[sam.length[i]]++;
  for (int i = 0; i < total; i++) c[i + 1] += c[i];
  for (int i = 0; i < total; i++) a[--c[sam.length[i]]] = i;
  reverse(a.begin(), a.end());
  for (int i = 1; i < n_p; i++) {
    vector<int> maxi(total);
    int len = 0;
    int curr = 0;
    for (auto&& c : paths[i]) {
      while (curr != -1 && sam.e[curr].count(c) == 0) {
        curr = sam.parent[curr];
        if (curr != -1) {
          len = sam.length[curr];
        }
      }
      if (curr == -1) {
        curr = 0;
        len = 0;
      } else {
        len++;
        curr = sam.e[curr][c];
        maxi[curr] = max(maxi[curr], len);
      }
    }
    for (int j = 0; j < total; j++) {
      int x = a[j];
      int p = sam.parent[x];
      if (p != -1) {
        maxi[p] = max(min(maxi[x], sam.length[p]), maxi[p]);
      }
      mini[x] = min(mini[x], maxi[x]);
    }
  }
  int res = 0;
  for (int j = 0; j < total; j++) {
    res = max(mini[j], res);
  }
  cout << res << "\n";
}