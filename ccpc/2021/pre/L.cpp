#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll T, n, P, p, maxi = 1e15;
  cin >> T;
  while (T--) {
    cin >> n >> P;
    set<vector<ll>> st;
    for (ll i = 0; i < P; i++) {
      cin >> p;
      st.insert({0, 0, p});
    }
    cout << endl;
    vector<ll> dp(n + 1, maxi);
    dp[0] = 0;
    for (ll i = 1; i <= n; i++) {
      auto it = st.begin();
      vector<ll> ps;
      while (st.size() > 0 && it != st.end() && (*it)[1] + (*it)[2] <= i) {
        ll x = (*it)[0], y = (*it)[1], z = (*it)[2];
        st.erase(it);
        if (y + z == i) {
          ps.push_back(z);
        } else {
          st.insert({dp[y + z], y + z, z});
        }
        it = st.begin();
      }
      if (it != st.end() && (*it)[0] != maxi) dp[i] = (*it)[0] + 1;
      for (ll pp : ps) {
        st.insert({dp[i], i, pp});
      }
    }
    __uint128_t mod = 1;
    for (int i = 1; i <= 64; i++) {
      mod *= 2;
    }
    __uint128_t res = 0, mul = 1;
    for (ll i = n; i > 0; i--, mul = (mul * (__uint128_t)23333) % mod) {
      if (dp[i] == maxi) continue;
      res = (res + (dp[i] * mul) % mod) % mod;
    }
    vector<int> ans;
    while (res) {
      ans.push_back(res % 10);
      res /= 10;
    }
    reverse(ans.begin(), ans.end());
    for (auto& x : ans) {
      cout << x;
    }
    cout << endl;
  }
}