#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  constexpr __int128 BASE = 5;
  constexpr __int128 MOD = 1e16 + 7;
  constexpr ull MAX_LEN = 20010;
  vector<__int128> power(MAX_LEN, 1);
  map<char, int> mp{{'m', 0}, {'e', 1}, {'t', 2}, {'a', 3}};

  for (int i = 1; i < MAX_LEN; i++) power[i] = power[i - 1] * BASE % MOD;
  for (int case_no = 1; case_no <= T; case_no++) {
    cout << "Case #" << case_no << ": ";
    int n;
    map<__int128, int> origin;
    map<__int128, int> one;
    cin >> n;
    for (int _ = 0; _ < n; _++) {
      string s;
      cin >> s;
      __int128 cur = 0;
      for (int i = 0; i < s.size(); i++) {
        (cur += mp[s[i]] * power[i] % MOD) %= MOD;
      }
      origin[cur]++;
      for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 4; j++) {
          if (mp[s[i]] == j) continue;
          __int128 temp = (cur - mp[s[i]] * power[i] % MOD + j * power[i] % MOD + MOD) % MOD;
          one[temp]++;
        }
      }
    }
    ull res = 0;
    int q;
    cin >> q;
    while (q--) {
      string s;
      cin >> s;
      __int128 cur = 0;
      for (int i = 0; i < s.size(); i++) {
        (cur += mp[s[i]] * power[i] % MOD) %= MOD;
      }
      for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 4; j++) {
          if (mp[s[i]] == j) continue;
          __int128 temp = (cur - mp[s[i]] * power[i] % MOD + j * power[i] % MOD + MOD) % MOD;
          res += one[temp];
          res -= origin[temp] * 2;
        }
        res -= origin[cur] * 3;
      }
    }
    cout << res / 2 << "\n";
  }
}
