#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll inf = 1e10;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;

  sort(a.begin(), a.end());

  for (int i = 0; i < n; i++) {
    a[i] += n - i;
  }

  vector<ll> pre_min(n + 1, inf);
  for (int i = 0; i < n; i++) pre_min[i + 1] = min(pre_min[i], a[i]);
  ll sum = accumulate(a.begin(), a.end(), 0ll);

  while (q--) {
    ll k;
    cin >> k;
    if (k < n) {
      cout << pre_min[k + 1] - (n - k) << " ";
      continue;
    }
    if ((k - n) % 2 == 1) {
      ll minus_cnt = (k - (n - 1)) / 2;
      ll layer = k - n;
      ll mini = min(pre_min[n - 1] + layer, a[n - 1] - 1);
      ll shield = (sum - 1) + layer * (n - 1) - mini * n;
      ll minus = (max(minus_cnt - shield, 0ll) + (n - 1)) / n;
      cout << mini - minus << " ";
    } else {
      ll minus_cnt = (k - n) / 2;
      ll layer = k - n;
      ll mini = pre_min[n] + layer;
      ll shield = sum + layer * n - mini * n;
      ll minus = (max(minus_cnt - shield, 0ll) + (n - 1)) / n;
      cout << mini - minus << " ";
    }
  }
}
