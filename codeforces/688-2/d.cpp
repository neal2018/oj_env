#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

void solve(ll k) {
  if (k & 1) {
    cout << -1 << '\n';
    return;
  }
  k /= 2;
  vector<int> res;
  int total = 0;
  while (k) {
    ll bit = 1;
    int cnt = 0;
    while (2 * bit - 1 <= k) bit *= 2, cnt++;
    k -= bit - 1;
    res.push_back(cnt);
    total += cnt;
  }
  cout << total << '\n';
  for (auto& x : res) {
    cout << 1 << ' ';
    for (int i = 1; i < x; i++) cout << 0 << ' ';
  }
  cout << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, k;
  cin >> T;
  while (T--) {
    cin >> k;
    solve(k);
  }
  
}