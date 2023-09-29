#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    ll cur = accumulate(a.end() - k, a.end(), 0ll);
    ll mini = cur;
    for (int i = -1, j = n - k; j < n;) {
      cur += a[i + 1] + a[i + 2];
      i = i + 2;
      cur -= a[j];
      j++;
      mini = min(mini, cur);
    }
    cout << sum - mini << "\n";
  }
}
