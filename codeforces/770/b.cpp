#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  for (; T--;) {
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    for (auto& xx : a) cin >> xx;
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    if (((sum % 2 == 0) ^ (x % 2 == y % 2)) == 0) {
      cout << "Alice\n";
    } else {
      cout << "Bob\n";
    }
  }
}