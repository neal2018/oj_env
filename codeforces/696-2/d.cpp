#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
constexpr ll MOD = 998244353;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  auto func = [&]() {
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    vector<ll> b(n);
    b[0] = a[0];
    for (int i = 1; i < n; i++) b[i] = a[i] - b[i - 1];
    auto check = [](multiset<ll>& my_st, ll x) { return my_st.size() == 0 || *my_st.begin() >= x; };
    vector<multiset<ll>> st(2), st2(2);
    for (int i = 0; i < n; i++) st[i % 2].insert(b[i]);
    if (check(st[0], 0) && check(st[1], 0) && b[n - 1] == 0) return true;
    for (int i = 0, f = 1; i < n - 1; i++, f = -f) {
      // swap a[i], a[i+1]
      ll diff = 2 * (a[i + 1] - a[i]) * f;
      ll update = b[n - 1] + ((n - 1) % 2 ? -1 : 1) * diff;
      st[i % 2].erase(st[i % 2].find(b[i]));
      if (update == 0 && b[i] - a[i] + a[i + 1] >= 0 && check(st2[0], 0) && check(st2[1], 0) &&
          check(st[0], -diff) && check(st[1], diff)) {
        return true;
      }
      st2[i % 2].insert(b[i]);
    }
    return false;
  };
  while (T--) cout << (func() ? "YES\n" : "NO\n");
}