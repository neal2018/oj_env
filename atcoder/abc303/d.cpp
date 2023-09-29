#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll x, y, z;
  string s;
  cin >> x >> y >> z >> s;
  ll a = 0, b = z;
  for (auto& c : s) {
    ll aa = 0, bb = 0;
    if (c == 'a') {
      aa = min({a + x, b + z + x, b + y + z});
      bb = min({b + y, a + x + z, b + z + y});
    } else {
      aa = min({a + y, b + x + z, b + z + y});
      bb = min({b + x, a + z + x, a + y + z});
    }
    a = aa, b = bb;
  }
  cout << min(a, b) << "\n";
}
