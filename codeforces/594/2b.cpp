#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  sort(a.begin(), a.end());
  ll one = accumulate(a.begin(), a.begin() + n / 2, 0ll);
  ll two = accumulate(a.begin() + n / 2, a.end(), 0ll);
  cout << one * one + two * two << "\n";
}
