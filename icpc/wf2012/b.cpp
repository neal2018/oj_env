#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;

const auto PI = acos(-1);
constexpr ld eps = 1e-12;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);
  ll T = 1, n;
  while (cin >> n) {
    cout << "Case " << T << ": ";
    vector<ld> a(n + 1);
    for (auto& x : a) cin >> x;
    vector<ld> aa(2 * n + 1);
    for (int i = 0; i <= 2 * n; i++) {
      for (int j = 0; j <= n; j++) {
        for (int k = 0; k <= n; k++) {
          if (j + k == i) {
            aa[i] += a[j] * a[k];
          }
        }
      }
    }
    // for (auto& x : aa) cout << x << " ";
    // cout << "\n";
    ll sz = aa.size();
    vector<ld> b(sz + 1);
    for (int i = 0; i < sz; i++) {
      b[i + 1] = aa[i] / (i + 1);
    }
    auto calc = [&](const vector<ld>& t, ld x) {
      ld res = 0;
      res += t[0];
      ld cur = x;
      for (int i = 1; i < t.size(); i++) {
        res += t[i] * cur, cur *= x;
      }
      return res;
    };
    ld low, high, inc;
    cin >> low >> high >> inc;
    ld total = (calc(b, high) - calc(b, low)) * PI;
    cout << total << "\n";
    vector<ld> res;
    ld pre = low;
    while (true) {
      if (res.size() >= 8) break;
      ld l = pre, r = high;
      for (int i = 0; i < 1000; i++) {
        ld mid = (l + r) / 2;
        auto area = (calc(b, mid) - calc(b, pre)) * PI;
        if (area < inc) {
          l = mid;
        } else {
          r = mid;
        }
      }
      // auto area = (calc(b, l) - calc(b, pre)) * PI;
      if (high - l < 0.01) {
        break;
      } else {
        res.push_back(l);
      }
      pre = l;
    }
    if (res.size()) {
      for (auto& x : res) cout << x - low << " ";
      cout << "\n";
    } else {
      cout << "insufficient volume\n";
    }
    T++;
  }
}
