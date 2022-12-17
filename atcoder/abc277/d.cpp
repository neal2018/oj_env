#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  map<int, int> cnt;
  for (auto& x : a) cnt[x]++;
  sort(a.begin(), a.end());
  int start = [&] {
    for (int i = 0; i < n; i++) {
      if (cnt.count((a[i] - 1 + m) % m) == 0) {
        return i;
      }
    }
    return 0;
  }();
  for (int i = 0; i < n; i++) a.push_back(a[i]);
  ll total = 0;
  for (int i = start, j = 0; i < start + n; i = j) {
    for (j = i + 1; j < start + n && (a[j - 1] == a[j] || a[j] == (a[j - 1] + 1) % m);) j++;
    ll cur = accumulate(a.begin() + i, a.begin() + j, 0ll);
    total = max(total, cur);
  }
  cout << accumulate(a.begin(), a.end(), 0ll) / 2 - total << "\n";
}
