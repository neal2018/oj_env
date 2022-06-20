#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    if (n & 1) {
      cout << "Mike\n";
    } else {
      vector<ll> odd, even;
      for (auto i : views::iota(0, n)) {
        ((i & 1) ? odd : even).push_back(a[i]);
      }
      auto get = [&](vector<ll>& v) {
        auto it = ranges::min_element(v);
        return v.size() * *it + (it - v.begin());
      };
      ll mike = get(even), joe = get(odd);
      if (mike > joe) {
        cout << "Mike\n";
      } else {
        cout << "Joe\n";
      }
    }
  }
}
