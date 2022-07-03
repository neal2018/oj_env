#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const ld PI = acos(-1);
using c = complex<ld>;

c power(c a, ll b, c res = 1) {
  for (; b; b /= 2, (a *= a))
    if (b & 1) (res *= a);
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n, k, d;
    cin >> n >> k, d = k / 2;
    auto w = c(cos(2 * PI / k), sin(2 * PI / k));
    auto s = [&] {
      ll l = 0, r = n;
      while (l < r) {
        ll mid = (l + r + 1) / 2;
        if (__int128(mid + 1) * mid / 2 <= n / d) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      return r;
    }();
    auto A = (power(w, s * d) - c(1)) / (power(w, d) - c(1)) - c(s) * power(w, s * d);
    A /= (c(1) - w);
    n -= d * (s + 1) * s / 2;
    ll t = n / (s + 1), remain = n % (s + 1);
    auto B = c(s + 1) * power(w, s * d) * ((power(w, t) - c(1)) / (w - c(1)));
    auto C = c(remain) * power(w, s * d + t);
    auto res = A + B + C;
    // cout << res.real() << " " << res.imag() << "\n";
    cout << res.real() + res.imag() << "\n";
  }
}
