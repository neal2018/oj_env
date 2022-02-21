#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  auto f = [&]() {
    string s;
    ll n, k, first = 0;
    cin >> n >> k >> s;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        if (k >= i - first) {
          swap(s[i], s[first]);
          k -= i - first;
          first++;
        } else {
          swap(s[i], s[i - k]);
          break;
        }
      }
    }
    cout << s << "\n";
  };
  while (T--) f();
}
