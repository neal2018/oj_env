#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    array<int, 2> a{};
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      if (s[0] != '0') a[0] += (s[0] == '1' ? 1 : -1);
      if (s[2] != '0') a[0] += (s[2] == '1' ? 1 : -1);
      if (s[1] != '0') a[1] += (s[1] == '1' ? 1 : -1);
      if (s[3] != '0') a[1] += (s[3] == '1' ? 1 : -1);
    }
    cout << 10 + a[0] + a[1] << "\n";
  }
}