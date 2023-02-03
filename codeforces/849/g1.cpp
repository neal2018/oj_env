#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    vector<ll> cost;
    for (int i = 0; i < n; i++) {
      cost.push_back(i + a[i] + 1);
    }
    sort(cost.begin(), cost.end());
    int i = 0;
    while (i < cost.size() && cost[i] <= c) {
      c -= cost[i], i++;
    }
    cout << i << "\n";
  }
}
