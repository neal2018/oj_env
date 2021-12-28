#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll MOD = 998244353;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  while (T--) {
    ll n, f = 1, cost = 0;
    cin >> n;
    vector<ll> a(n), cnt(n + 1), stk;
    for (auto& x : a) cin >> x, cnt[x]++;
    for (int v = 0; v <= n; v++) {
      cout << (f ? cost + cnt[v] : -1) << ' ';
      while (cnt[v]--) stk.push_back(v);
      stk.size() ? cost += v - stk.back(), stk.pop_back(), 0 : f = 0;
    }
    cout << '\n';
  }
}
