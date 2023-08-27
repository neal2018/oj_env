#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s;
    int n, k;
    cin >> n >> k >> s;
    if (k % 2 == 0) {
      sort(s.begin(), s.end());
      cout << s << "\n";
    } else {
      string a, b;
      for (int i = 0; i < n; i++) {
        (i % 2 == 0 ? a : b) += s[i];
      }
      sort(a.begin(), a.end());
      sort(b.begin(), b.end());
      for (int i = 0, ai = 0, bi = 0; i < n; i++) {
        cout << (i % 2 == 0 ? a[ai++] : b[bi++]);
      }
      cout << "\n";
    }
  }
}
