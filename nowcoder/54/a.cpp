#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  string s;
  cin >> n >> s;
  s = s + s;
  vector<ll> pre(2 * n + 2);  // number of 0;
  for (int i = 0; i < 2 * n; i++) pre[i + 1] = pre[i] + (s[i] == '0');
  ll total_0 = pre[n], res = 0;
  if (total_0 & 1) {
    cout << 0 << '\n';
    return 0;
  }
  for (int i = 0; i < n; i++) {
    // color [i, i+n/2-1]
    if (pre[i + n / 2] - pre[i] == total_0 / 2) {
      res++;
    }
  }
  cout << res << '\n';
}