#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    for (auto& x : a) {
      ll y;
      cin >> y;
      x -= y;
    }
    auto maxi = *max_element(a.begin(), a.end());
    vector<int> res;
    for (int i = 0; i < n; i++) {
      if (a[i] == maxi) res.push_back(i);
    }
    cout << res.size() << "\n";
    for (auto& x : res) cout << x + 1 << " ";
    cout << "\n";
  }
}
