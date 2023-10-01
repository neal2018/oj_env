#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    auto min_a_it = min_element(a.begin(), a.end());
    auto max_b_it = max_element(b.begin(), b.end());
    k--;
    if (*min_a_it > *max_b_it) {
    } else {
      swap(*min_a_it, *max_b_it);
    }
    if (k % 2 == 0) {
      cout << accumulate(a.begin(), a.end(), 0ll) << "\n";
    } else {
      auto min_a_it2 = max_element(a.begin(), a.end());
      auto max_b_it2 = min_element(b.begin(), b.end());
      swap(*min_a_it2, *max_b_it2);
      cout << accumulate(a.begin(), a.end(), 0ll) << "\n";
    }
  }
}
