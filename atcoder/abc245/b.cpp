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
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  ll cur = 0;
  for (auto& x : a) {
    if (x != cur) {
      cout << cur << "\n";
      return 0;
    }
    cur++;
  }
  cout << cur << "\n";
}
