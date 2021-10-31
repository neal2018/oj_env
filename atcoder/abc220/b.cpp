#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll a, b, k;
  cin >> k >> a >> b;
  auto get = [&](ll a) {
    if (a == 0) return 0ll;
    vector<ll> t;
    ll x = 0;
    while (a > 0) {
      t.push_back(a % 10);
      a /= 10;
    }
    reverse(t.begin(), t.end());
    for (auto& tt : t) {
      x = x * k + tt;
    }
    return x;
  };
  ll x = get(a), y = get(b);
  // cout << x << " " << y << endl;
  cout << x * y << endl;
}