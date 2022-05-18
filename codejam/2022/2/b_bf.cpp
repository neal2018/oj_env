#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

constexpr ld eps = 1e-10;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  for (int case_num = 1; case_num <= T; case_num++) {
    cout << "Case #" << case_num << ": ";
    ll R;
    cin >> R;
    vector<vector<ll>> circle(2 * R + 1, vector<ll>(2 * R + 1));
    vector<vector<ll>> circle_wrong(2 * R + 1, vector<ll>(2 * R + 1));
    auto my_round = [&](ld x) -> ll { return ceil(x - 0.5 - eps); };
    auto set_pixel_to_black = [&](ll x, ll y, vector<vector<ll>>& c) { c[x + R][y + R] = 1; };
    auto draw_circle_perimeter = [&](ll r) {
      for (ll x = -r; x <= r; x++) {
        ll y = my_round(sqrt(r * r - x * x));
        set_pixel_to_black(x, y, circle_wrong);
        set_pixel_to_black(x, -y, circle_wrong);
        set_pixel_to_black(y, x, circle_wrong);
        set_pixel_to_black(-y, x, circle_wrong);
      }
    };
    auto draw_circle_filled = [&](ll r) {
      for (ll x = -r; x <= r; x++) {
        for (ll y = -r; y <= r; y++) {
          ll dis = my_round(sqrt(x * x + y * y));
          if (dis <= r) set_pixel_to_black(x, y, circle);
        }
      }
    };
    auto draw_circle_filled_wrong = [&](ll r) {
      for (ll i = 0; i <= r; i++) draw_circle_perimeter(i);
    };
    draw_circle_filled(R);
    draw_circle_filled_wrong(R);
    ll cnt = 0;
    for (int i = 0; i < 2 * R + 1; i++) {
      for (int j = 0; j < 2 * R + 1; j++) {
        if (circle_wrong[i][j] != circle[i][j]) {
          cnt++;
        }
      }
    }
    cout << cnt / 4 << "\n";
    // if (case_num == 16) {
      for (auto& r : circle) {
        for (auto& x : r) cout << x;
        cout << "\n";
      }
      cout << "\n";
      for (auto& r : circle_wrong) {
        for (auto& x : r) cout << x;
        cout << "\n";
      }
      cout << "\n";
    // }
  }
}
