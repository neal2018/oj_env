#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  string s;
  cin >> n >> k >> s;
  string ans(k, 'z');
  for (int i = 1; i <= n; i++) {
    string t = s.substr(0, i);
    while (t.size() < k) t += t;
    t = t.substr(0, k);
    if (t < ans) ans = t;
  }
  cout << ans << '\n';
}
