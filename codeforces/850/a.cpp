#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, maxi = 0;
    cin >> n;
    vector<ll> a(n), freq(n);
    for (auto& x : a) cin >> x, maxi = max(maxi, x), x--, freq[x]++;
    ll res = 0;
    for (int i = 0, j = 0; i < maxi; i++) {
      j = max(j, i);
      while (j < maxi && freq[j] == 0) j++;
      if (j == maxi) break;
      freq[i]++, freq[j]--, res += j - i;
    }
    cout << res << "\n";
  }
}
