#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, a, b;
  cin >> n >> a >> b;
  ll res = n * (n + 1) / 2;
  ll t = lcm(a, b);
  ll a_cnt = n / a, b_cnt = n / b, ab_cnt = n / t;
  res -= a * (a_cnt * (a_cnt + 1) / 2);
  res -= b * (b_cnt * (b_cnt + 1) / 2);
  res += t * (ab_cnt * (ab_cnt + 1) / 2);
  cout << res << "\n";
}