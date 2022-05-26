#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  auto func = [&]() {
    string s;
    cin >> s;
    for (int i = 0; i < (1 << 3); i++) {
      int a[3] = {0, 0, 0};
      if (i & 1) a[0] = 1;
      if (i & 2) a[1] = 1;
      if (i & 4) a[2] = 1;
      auto t = s;
      for (auto& c : t) {
        c = a[c - 'A'] ? '(' : ')';
      }
      ll cnt = 0, f = 1;
      for (auto& c : t) {
        cnt += c == '(' ? 1 : -1;
        if (cnt < 0) f = 0;
      }
      if (cnt != 0) f = 0;
      if (f) {
        return true;
      }
    }
    return false;
  };
  int T;
  cin >> T;
  while (T--) cout << (func() ? "YES\n" : "NO\n");
}
