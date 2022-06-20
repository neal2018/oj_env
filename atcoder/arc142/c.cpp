#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr int MAX = 31;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  ll maxi = *max_element(a.begin(), a.end());
  ll res = 0;
  for (int i = 0; i < n; i++) res += abs(a[i] - a[(i + 1) % n]);
  cout << max(maxi, res/2) << "\n";
}
