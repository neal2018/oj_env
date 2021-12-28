#include <bits/stdc++.h>
using namespace std;
#define ll long long
// https://space.bilibili.com/672328094
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  auto is_sq = [&](ll x) { return (ll)sqrt(x) * (ll)sqrt(x) == x; };
  auto get_wont = [&]() -> vector<ll> {
    if (n % 4 == 0) return {n / 2};
    if (n == 1) return {};
    if (n % 4 == 1) return {n / 2, n};
    if (n % 4 == 2) {
      if (is_sq(n + 2)) return {n / 2 + 1};
      if (is_sq(n * (n / 2 + 1))) return {n / 2 - 2};
      return {n / 2, 2};
    }
    if (is_sq(n + 1)) return {n / 2 + 1, n};
    if (is_sq(2 * (n / 2) * (n / 2 - 1))) return {n / 2 - 2, n};
    if (is_sq((n / 2 - 1) * n)) return {n / 2 - 2, n - 2};
    return {2, n / 2, n};
  };
  auto wont = get_wont();
  cout << n - wont.size() << "\n";
  for (int i = 1; i <= n; i++)
    if (find(wont.begin(), wont.end(), i) == wont.end()) cout << i << " ";
  cout << "\n";
}
