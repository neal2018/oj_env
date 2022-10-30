#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  ll res = 100, cur = 100;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    cur += x;
    res = max(res, cur);
  }
  cout << res << "\n";
}
