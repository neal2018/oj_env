#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  int n;
  cin >> n;
  vector<string> a(n);
  for (auto& s : a) cin >> s;
  ll res = 0;
  int one = (1 << 26) - 1;
  vector<int> cnt(n), odd(n);
  vector<int> mp(1 << 26);
  for (int i = 0; i < n; i++) {
    for (auto& c : a[i]) {
      int c_bit = 1 << (c - 'a');
      cnt[i] |= c_bit, odd[i] ^= c_bit;
    }
  }
  for (int _ = 0; _ < 26; _++) {
    int bit = (1 << _);
    for (int i = 0; i < n; i++) {
      if (cnt[i] & bit) continue;
      int odd_need = (odd[i] ^ one ^ bit);
      res += mp[odd_need];
      mp[odd[i]]++;
    }
    for (int i = 0; i < n; i++) {
      mp[odd[i]] = 0;
    }
  }
  cout << res << "\n";
}
