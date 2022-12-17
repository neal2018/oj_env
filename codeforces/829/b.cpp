#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, t;
  cin >> n >> t;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  sort(a.begin(), a.end());
  int pre = 0;
  for (int i = 1, j = 0; i <= t && j < n; i++) {
    while (j < n && a[j] < i) j++, pre++;
    if (pre % i) {
      cout << "No\n";
      return 0;
    }
    pre /= i;
  }
  cout << "Yes\n";
}
