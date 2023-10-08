
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
    set<int> need;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        for (int t = i + 1; t <= n; t += i + 1) {
          s[t - 1] ^= '0' ^ '1';
        }
        need.insert(i);
      }
    }
    ll res = 0;
    while (q--) {
      int x;
      cin >> x, x--;
      if (need.count(x)) {
        need.erase(x);
      } else {
        need.insert(x);
      }
      res += need.size();
    }
    cout << "Case #" << test_case_no << ": " << res << "\n";
  }
}
