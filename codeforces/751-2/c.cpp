#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
ll T, n;
void solve() {
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  int t = 0;
  for (int i = 0; i < 30; i++) {
    int cnt = 0;
    for (auto& x : a) {
      int tmp = (x >> i) & 1;
      cnt += tmp;
    }
    if (cnt != 0) {
      if (t == 0) {
        t = cnt;
      } else {
        t = __gcd(t, cnt);
      }
    }
  }
  if (t == 0) {
    for (int i = 1; i <= n; i++) {
      cout << i << " ";
    }
  } else {
    set<int> ans;
    for (int i = 1; i * i <= t; i++) {
      if (t % i == 0) {
        ans.insert(i);
        ans.insert(t / i);
      }
    }
    for (auto& x : ans) {
      cout << x << " ";
    }
  }
  cout << '\n';
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> T;
  while (T--) {
    solve();
  }
}