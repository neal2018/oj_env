#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    auto even = ranges::count_if(a, [](auto x) { return x % 2 == 0; });
    auto mini = ranges::min(a | views::transform([](auto x) {
                              int cur = 0;
                              while (x % 2 == 0) cur++, x /= 2;
                              return cur;
                            }));
    cout << mini + even - (even == n) << "\n";
  }
}
