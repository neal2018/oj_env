#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    ll res = n;
    for (int i : views::iota(1, n)) {
      if (s[i] ^ s[i - 1]) res += i;
    }
    cout << res << "\n";
  }
}
