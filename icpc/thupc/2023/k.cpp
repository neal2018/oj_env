#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll inf = 1e18;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<array<ll, 2>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i][0], a[i][1] = i;
  }
  sort(a.begin(), a.end());
  vector<ll> pos(n);
  for (int i = 0; i < n; i++) {
    auto [freq, v] = a[i];
    pos[v] = i;
  }
  vector<ll> pre(n + 1);
  for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i][0];
  ll res = 0, minus = 0, right = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (pos[i] < right) continue;
    auto freq = a[pos[i]][0];
    auto limit = ll(upper_bound(a.begin(), a.end(), array<ll, 2>{freq, inf}) - a.begin());
    auto add = pre[limit] - pre[right];
    add -= minus * (limit - right);
    add += (n - limit) * (freq - minus);

    res += add * (i + 1);

    minus = freq;
    right = limit;
  }
  cout << res << "\n";
}
