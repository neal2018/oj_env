#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094 1:53
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, a;
  cin >> T;
  auto solve = [&] {
    vector<int> q{0}, nq;
    unordered_set<int> st{0};
    for (int step = 1; q.size(); swap(q, nq), nq.clear(), step++) {
      for (auto& x : q) {
        if (x == a) {
          cout << step - 1 << '\n';
          return;
        }
        // if (!st.count(x + step)) {
          nq.push_back(x + step);
        // }
        // if (!st.count(x - 1)) {
          nq.push_back(x - 1);
        // }
      }
    }
  };
  while (T--) {
    cin >> a;
    solve();
  }
}