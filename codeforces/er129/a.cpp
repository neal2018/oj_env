#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, m;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    cin >> m;
    vector<ll> b(m);
    for (auto& x : b) cin >> x;
    ll amax = *max_element(a.begin(), a.end());
    ll bmax = *max_element(b.begin(), b.end());
    if (amax > bmax) {
      cout << "Alice\nAlice\n";
    } else if (bmax > amax) {
      cout << "Bob\nBob\n";
    } else {
      cout << "Alice\nBob\n";
    }
  }
}
