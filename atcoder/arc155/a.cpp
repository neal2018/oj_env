#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, k;
    string s;
    cin >> n >> k >> s;
    auto solve = [&] {
      auto check = [&](ll x) {
        if (k % x != 0) return false;
        string base = s.substr(0, x);
        string rev(base.rbegin(), base.rend());
        string res;
        string res_o;
        for (int i = 0; i * x < n; i++) {
          if (i % 2 == 0) {
            res += base;
          } else {
            res += rev;
          }
          res_o += base;
        }
        if (res == s && (k / x + n / x) % 2 == 0) {
          return true;
        }
        if ((base == string(base.rbegin(), base.rend())) && res_o == s && (k / x + n / x) % 2 == 1) {
          return true;
        }
        return false;
      };
      for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
          if (check(i)) return true;
          if (check(n / i)) return true;
        }
      }
      return false;
    };
    cout << (solve() ? "Yes\n" : "No\n");
  }
}