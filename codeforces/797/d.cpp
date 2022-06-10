#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, k;
    string s;
    cin >> n >> k >> s;
    ll cur = 0, res = n;
    for (int i : views::iota(0, n)) {
      cur += (s[i] == 'W');
      if (i - k >= 0) cur -= (s[i - k] == 'W');
      if (i - k + 1 >= 0) res = min(res, cur);
    }
    cout << res << "\n";
  }
}
