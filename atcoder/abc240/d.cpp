#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  int cnt = 0;
  vector<pair<int, int>> stk;
  for (auto& x : a) {
    if (stk.empty() || stk.back().first != x) {
      cnt = 1;
    } else {
      cnt++;
    }
    stk.push_back({x, cnt});
    if (cnt == x) {
      while (cnt--) stk.pop_back();
      cnt = stk.size() ? stk.back().second : 0;
    }
    cout << stk.size() << "\n";
  }
}


