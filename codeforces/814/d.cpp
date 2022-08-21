#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ask(int a, int b) {
  cout << "? " << a + 1 << " " << b + 1 << endl;
  int res;
  cin >> res;
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    function<int(int, int)> dfs = [&](int start, int len) {
      if (len == 0) return start;
      if (len & 1) {
        auto x = dfs(start, len - 1), y = dfs(start + (1 << (len - 1)), len - 1);
        return (ask(x, y) == 1) ? x : y;
      } else {
        int n_len = 1 << (len - 2);
        auto a = dfs(start, len - 2), b = dfs(start + n_len, len - 2);
        auto c = dfs(start + 2 * n_len, len - 2), d = dfs(start + 3 * n_len, len - 2);
        int x = ask(a, c);
        if (x == 0) {
          // a, c lose
          return (ask(b, d) == 1) ? b : d;
        } else if (x == 1) {
          // a win, or d win
          return (ask(a, d) == 1) ? a : d;
        } else {
          // b win, or c win
          return (ask(b, c) == 1) ? b : c;
        }
      }
    };
    int res = dfs(0, n);
    cout << "! " << res + 1 << endl;
  }
}
