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
    vector<int> a(n), freq(n);
    for (auto& x : a) cin >> x, x--, freq[x]++;

    multiset<int> spare;
    ll cost = 0, maxi = 0;
    for (int j = 0; j < n;) {
      while (j < n && freq[j] == 0) j++;
      if (j == n) break;
      freq[j]--, cost += j - maxi, maxi++;
      while (j < maxi) {
        while (freq[j]) spare.insert(j), freq[j]--;
        j++;
      }
    }

    vector<ll> res(n);
    for (int i = n - 1; i >= 0; i--) {
      res[i] = cost;
      if (auto it = spare.lower_bound(a[i]); it != spare.end()) {
        cost += spare.extract(it).value() - a[i];
      } else {
        cost += maxi - 1 - a[i], maxi--;
      }
    }
    for (auto& x : res) cout << x << " ";
    cout << "\n";
  }
}
