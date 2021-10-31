#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int inf = 1e9;

ll solve(ll x, ll y) {
  if (y % x == 0) return x;
  if (x > y) return x + y;
  if (x * 2 > y) return (x + y) / 2;
  ll A = y / x - 1;
  ll t = (y - A * x) / 2;
  return y - t;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, x, y;
  cin >> T;
  while (T--) {
    cin >> x >> y;
    ll t = solve(x, y);
    cout << t << '\n';
    // cout << t % x << " " << y % t << endl;
  }
}