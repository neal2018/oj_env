#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll T, n;
  string s;
  cin >> T;
  auto solve = [&]() {
    cin >> n >> s;
    int it = s.find('0');
    if (it == string::npos) {
      cout << 1 << " " << (n + 1) / 2 << " " << (n + 1) / 2 + (n % 2 == 0) << " " << n << endl;
      return;
    }
    int it2 = n;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '0') {
        it2 = i;
        break;
      }
    }
    if (it2 == n) it2 = it;
    // cout << it << " " << it2 << endl;
    if ((n & 1) && it == n / 2 && it == it2) {
      cout << 1 << " " << it + 1 << " " << it + 1 << " " << n << endl;
      return;
    }
    if (it2 >= n / 2) {
      cout << 1 << " " << it2 + 1 << " " << 1 << " " << it2 << endl;
    } else {
      cout << it + 1 << " " << n << " " << it + 2 << " " << n << endl;
    }
  };
  while (T--) {
    solve();
  }
}