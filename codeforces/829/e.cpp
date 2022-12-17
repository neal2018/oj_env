#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    auto max_a = a;
    for (int i = 1; i < n; i++) max_a[i] = max(max_a[i - 1], a[i]);
    vector<ll> pre_a(n + 1);
    for (int i = 0; i < n; i++) pre_a[i + 1] = pre_a[i] + a[i];
    while (q--) {
      int k;
      cin >> k;
      auto it = upper_bound(max_a.begin(), max_a.end(), k);
      cout << pre_a[(it - max_a.begin())] << ' ';
    }
    cout << "\n";
  }
}
