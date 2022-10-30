#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    char t;
    string s;
    cin >> n >> t >> s;
    s += s;
    vector<int> dist(2 * n);
    for (int i = 2 * n - 1, cur = 0; i >= 0; i--) {
      if (s[i] == 'g') {
        cur = 0;
      } else {
        cur++;
      }
      dist[i] = cur;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == t) res = max(res, dist[i]);
    }
    cout << res << "\n";
  }
}
