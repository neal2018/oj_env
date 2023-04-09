#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  sort(a.begin(), a.end());
  ll addon = 0;
  vector<ll> power(n, 1);
  for (int i = 1; i < n; i++) power[i] = power[i - 1] * 2 % MOD;
  for (; n > 1; n--) {
    ll mini = a[0];
    (addon += (power[n - 1] * mini) % MOD) %= MOD;
    for (auto& x : a) x -= mini;

    set<array<ll, 3>> st{{a[0] + a[1], 0, 1}};
    set<ll> seen{1};
    vector<ll> f;
    for (int _ = 0; _ < n - 1; _++) {
      auto [val, i, j] = *st.begin();
      st.erase(st.begin());
      f.push_back(val);
      if (i + 1 < j && seen.count((i + 1) * n + j) == 0) {
        seen.insert((i + 1) * n + j);
        st.insert({a[i + 1] + a[j], i + 1, j});
      }
      if (j + 1 < n && seen.count(i * n + j + 1) == 0) {
        seen.insert(i * n + j + 1);
        st.insert({a[i] + a[j + 1], i, j + 1});
      }
    }
    swap(f, a);
  }
  cout << (a[0] + addon) % MOD << "\n";
}
