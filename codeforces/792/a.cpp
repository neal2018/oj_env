#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    auto s = to_string(n);
    if (s.size() == 2) {
      cout << s[1] << "\n";
    } else {
      cout << *min_element(s.begin(), s.end()) << "\n";
    }
  }
}
