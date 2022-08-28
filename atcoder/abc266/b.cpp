#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

ll floor_div(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b != 0); }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  constexpr ll P = 998244353;
  ll nex = floor_div(n, P) * P;
  cout << n - nex << "\n";
}
