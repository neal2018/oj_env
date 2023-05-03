#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, l, r;
  cin >> n >> l >> r;
  map<int, int> memo;
  function<int(int)> dfs = [&](int len) {
    if (len < l) return 0;
    if (memo.find(len) != memo.end()) return memo[len];
    set<int> st;
    for (int t = l; t <= r; t++) {
      for (int i = 0; len - t - i >= 0; i++) {
        st.insert((dfs(i) ^ dfs(len - t - i)));
      }
    }
    for (int i = 0; i < 500; i++) {
      if (st.find(i) == st.end()) return memo[len] = i;
    }
    throw;
  };
  // for (int i = 0; i < 500; i++) {
  //   cout << i << " " << dfs(i) << "\n";
  // }
  map<int, int> memo_ring;
  function<int(int)> dfs_ring = [&](int len) {
    if (len < l) return 0;
    if (memo_ring.find(len) != memo_ring.end()) return memo[len];
    set<int> st;
    for (int t = l; t <= r; t++) {
      int remain = len - t;
      st.insert(dfs(remain));
    }
    for (int i = 0; i < 500; i++) {
      if (st.find(i) == st.end()) return memo_ring[len] = i;
    }
    throw;
  };
  for (int i = 0; i < 500; i++) {
    cout << i << " " << dfs_ring(i) << "\n";
  }
}
