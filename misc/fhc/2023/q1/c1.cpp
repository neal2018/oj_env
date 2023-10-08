
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int T;
  cin >> T;

  for (int test_case_no = 1; test_case_no <= T; test_case_no++) {
    int n, q;
    string s;
    cin >> n >> s >> q;
    vector<int> flipped(n);
    while (q--) {
      int x;
      cin >> x, x--;
      flipped[x] ^= 1;
    }
    for (int i = 0; i < n; i++) {
      if (flipped[i] == 1) {
        for (int t = i + 1; t <= n; t += i + 1) {
          s[t - 1] ^= '0' ^ '1';
        }
      }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        for (int t = i + 1; t <= n; t += i + 1) {
          s[t - 1] ^= '0' ^ '1';
        }
        res++;
      }
    }
    cout << "Case #" << test_case_no << ": " << res << "\n";
  }
}
