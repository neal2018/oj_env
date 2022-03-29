#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  ll cur = 0, cnt = 0, pre = a[0], done = 0;
  for (auto &x : a) {
    ll nex = (x - pre) * cnt + cur;
    pre = x;
    if (nex >= 20) {
      cur = 0, cnt = 1;
      done++;
    } else {
      cur = nex, cnt++;
    }
  }
  if (cnt) done++;
  cout << done << "\n";
}