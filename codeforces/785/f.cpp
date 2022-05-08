#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  vector<int> a = {1, 2, 1, 4, 1, 2, 1, 8, 1, 2, 1, 4, 1, 2, 1, 16,
                   1, 2, 1, 4, 1, 2, 1, 8, 1, 2, 1, 4, 1, 2, 1};
  map<ll, ll> mp{{0, 0}};
  for (ll i = 0, t = 0; i < 31; i++) {
    t ^= a[i], mp[t] = i + 1;
  }
  map<ll, ll> enlarge{{1, 1}, {2, 4}, {4, 16}, {8, 64}, {16, 256}};

  ll n, k;
  cin >> n >> k;
  ll cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      cout << enlarge[a[j]] << " ";
      cnt += enlarge[a[j]];
    }
    cout << "\n";
  }
  // cout << cnt << "\n";
  for (int j = 0; j < n - 1; j++) {
    for (int i = 0; i < n; i++) {
      cout << enlarge[a[j]] * 2 << " ";
      cnt += enlarge[a[j]] * 2;
    }
    cout << "\n";
  }
  cout << endl;
  // cout << cnt << "\n";
  ll x = 0;
  while (k--) {
    ll t;
    cin >> t;
    x ^= t;
    ll col = 0, row = 0;
    for (int i = 0; i < 10; i++) {
      if (x & (1 << i)) {
        ((i & 1) ? row : col) |= (1 << (i / 2));
      }
    }
    cout << mp[row] + 1 << " " << mp[col] + 1 << endl;
  }
}
