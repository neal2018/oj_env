#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    map<ll, ll> freq;
    for (auto& x : a) freq[x]++;
    ll res = 0;
    for (auto& [k, v] : freq) {
      res += v * (v - 1) * (v - 2);
      for (int i = 2; i * i <= k; i++) {
        if (k % (i * i) == 0) {
          res += v * freq[k / i] * freq[k / i / i];
        }
      }
    }
    cout << res << "\n";
  }
}
