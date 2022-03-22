#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, k, f = 0;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    if (find(a.begin(), a.end(), k) == a.end()) {
      cout << "NO\n";
      continue;
    }
    if (n == 1) {
      f = 1;
    }
    if (n == 2) {
      if (*min_element(a.begin(), a.end()) >= k) f = 1;
    }
    for (int i = 0; i < n - 2; i++) {
      int cnt = 0;
      for (int j = i; j < i + 3; j++) cnt += (a[j] >= k);
      if (cnt >= 2) f = 1;
    }
    cout << (f ? "YES\n" : "NO\n");
  }
}
