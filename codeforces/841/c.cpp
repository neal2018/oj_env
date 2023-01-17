#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int MAX_N = 1 << 20;
  vector<int> good;
  for (ll i = 0; i * i <= MAX_N; i++) {
    good.push_back(i * i);
  }
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<int> mp(n * 2 + 1);
    mp[0] = 1;
    ll res = 0;
    int cur = 0;
    for (auto& x : a) {
      cur ^= x;
      for (auto& t : good) {
        if ((cur ^ t) <= 2 * n) res += mp[cur ^ t];
      }
      mp[cur]++;
    }
    cout << (n * (n + 1)) / 2 - res << "\n";
  }
}
