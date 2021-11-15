#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  ll res = 0;
  for (ll a = 1; a * a * a <= n; a++) {
    for (ll b = a; a * b * b <= n && n / (a * b) >= b; b++) {
      res += (n / (a * b) - b + 1);
    }
  }
  cout << res << '\n';
}