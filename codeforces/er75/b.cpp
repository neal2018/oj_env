#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<string> s(n);
    for (auto& x : s) cin >> x;
    // sz even: 0 even, 1 even
    // sz  odd: ok
    ll has_odd = 0, zero = 0, one = 0;
    for (auto& x : s) {
      if (x.size() & 1) has_odd = 1;
      zero += count(x.begin(), x.end(), '0');
      one += count(x.begin(), x.end(), '1');
    }
    if (!has_odd && (zero & 1)) {
      cout << n - 1 << "\n";
    } else {
      cout << n << "\n";
    }
  }
}
