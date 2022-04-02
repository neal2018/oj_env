#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int k;
  cin >> k;
  string s, t;
  cin >> s >> t;
  int same = 0, n = int(s.size());
  for (int i = 0; i < n; i++) {
    if (s[i] == t[i]) same++;
  }
  int res = n - abs(k - same);
  cout << res << "\n";
}