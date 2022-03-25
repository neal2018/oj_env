#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    ll mini = min_element(a.begin(), a.end()) - a.begin();
    ll maxi = max_element(a.begin(), a.end()) - a.begin();
    cout << maxi + 1 << " " << mini + 1 << "\n";
  }
}
