#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using i128 = __int128;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, x;
  cin >> n >> x;
  // ll res2;
  // {
  //   ll res = 100;
  //   function<void(i128, ll)> dfs = [&](i128 cur, ll cnt) {
  //     if (cnt >= res) return;
  //     string s = "";
  //     auto t = cur;
  //     while (cur) {
  //       s += cur % 10 + '0', cur /= 10;
  //     }
  //     reverse(s.begin(), s.end());
  //     // cout << s << " " << (ll)cur << "\n";
  //     if (s.size() == n) {
  //       res = min(res, cnt);
  //       return;
  //     }
  //     if (s.size() > n) {
  //       return;
  //     }
  //     char a[10]{};
  //     for (auto& c : s) a[c - '0'] = 1;
  //     for (int i = 9, go = 0; i >= 2; i--) {
  //       if (a[i]) {
  //         // if ((i128)cur * i > LONG_LONG_MAX) continue;
  //         dfs(t * i, cnt + 1);
  //         if (++go > 1) break;
  //       }
  //     }
  //   };
  //   dfs(x, 0);
  //   res2 = res;
  // }
  // {
    ll res = 100;
    function<void(ll, ll)> dfs = [&](ll cur, ll cnt) {
      // cout << cur << '\n';
      auto s = to_string(cur);
      if (s.size() == n) {
        res = min(res, cnt);
        return;
      }
      if (cnt + n - s.size() >= res) return;
      if (s.size() > n) {
        return;
      }
      char a[10]{};
      for (auto& c : s) a[c - '0'] = 1;
      for (int i = 9, go = 0; i >= 2; i--) {
        if (a[i]) {
          dfs(cur * i, cnt + 1);
          // if (++go > 1) break;
        }
      }
    };
    dfs(x, 0);
    // assert(res == res2);
    // cout << res << ' ' << res2 << "\n";
  // }
  cout << (res == 100 ? -1 : res) << "\n";
}
