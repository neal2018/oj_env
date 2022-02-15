#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> s(n);
  for (auto& x : s) cin >> x;
  vector<ll> mini(n + 2);
  for (ll i = n - 1; i > 0; i--) {
    mini[i - 1] = mini[i + 2] - s[i] + s[i - 1];
  }
  if (s[0] - mini[0] - mini[1] < mini[2]) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
    cout << mini[0] << " " << mini[1] << " " << (mini[2] = s[0] - mini[0] - mini[1]) << " ";
    for (int i = 1; i < n; i++) {
      cout << (mini[i + 2] = s[i] - s[i - 1] + mini[i - 1]) << " \n"[i == n - 1];
    }
  }
}

// s[0] = a[0] + a[1] + a[2]
// s[1] = a[1] + a[2] + a[3]
// s[2] = a[2] + a[3] + a[4]
// s[3] = a[3] + a[4] + a[5]

// s[0] - a[0] - a[1] = a[2]

// s[1] - a[1] - a[2] = a[3]
// s[1] - s[0] + a[0] = a[3]

// s[2] - a[2] - a[3] = a[4]
// s[2] - s[1] + a[1] = a[4]

// s[3] - a[3] - a[4] = a[5]
// s[3] - s[2] + a[2] = a[5]
