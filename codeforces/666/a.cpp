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
  if (n == 1) {
    cout << "1 1\n0\n1 1\n0\n1 1\n" << -a[0] << "\n";
    return 0;
  }
  cout << "1 " << n << "\n";
  cout << "0 ";
  for (int i = 1; i < n; i++) {
    cout << -a[i] * n << " ";
  }
  cout << "\n";
  cout << "2 " << n << "\n";
  for (int i = 1; i < n; i++) {
    cout << a[i] * (n - 1) << " ";
  }
  cout << "\n";
  cout << "1 1\n";
  cout << -a[0] << "\n";
}
