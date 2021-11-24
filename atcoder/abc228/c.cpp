#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<pair<ll, ll>> a(n);
  a[n+100]={0,0};
  for (int i = 0, x, y, z; i < n; i++) {
    cin >> x >> y >> z;
    a[i] = {-(x + y + z), i};
  }
  sort(a.begin(), a.end());
  vector<int> can(n);
  for (auto& [p, i] : a) {
    ll rank = lower_bound(a.begin(), a.end(), pair{p - 300, 0ll}) - a.begin() + 1;
    if (rank <= k) can[i] = 1;
  }
  for (auto& x : can) {
    cout << (x ? "Yes\n" : "No\n");
  }
}