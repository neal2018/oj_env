#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, p;
    cin >> n >> p;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    map<ll, ll> mp;
    for (auto& x : a) mp[x]++;
    auto get = [&] {
      ll start = a.back();
      ll cnt = 0;
      while (mp.count(start) > 0 && cnt < p) cnt++, start = (start - 1 + p) % p;
      return cnt;
    };
    ll need = p - get();
    {
      ll req = p - a.back();
      auto b = a;
      ll carry = 0;
      b.back() += p - a.back();
      for (int i = n - 1; i >= 0; i--) {
        b[i] += carry;
        carry = b[i] / p;
        b[i] %= p;
      }
      for (auto& x : b) mp[x]++;
      if (carry) mp[carry]++;
      need = min(need, max(req, p - get()));
    }
    cout << need << "\n";
  }
}
