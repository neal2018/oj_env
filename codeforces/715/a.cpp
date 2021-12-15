#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  string s1, s2, s3;
  cin >> T;
  for (int n, xx = 0; xx < T; xx++) {
    cin >> n >> s1 >> s2 >> s3;
    ll z1 = count(s1.begin(), s1.end(), '0');
    ll z2 = count(s2.begin(), s2.end(), '0');
    ll z3 = count(s3.begin(), s3.end(), '0');
    char c = '0';
    if ((z1 < n) + (z2 < n) + (z3 < n) >= 2) {
      c = '1', z1 = 2 * n - z1, z2 = 2 * n - z2, z3 = 2 * n - z3;
    }
    string_view x, y;
    if (z1 >= n && z2 >= n) x = s1, y = s2;
    if (z2 >= n && z3 >= n) x = s2, y = s3;
    if (z1 >= n && z3 >= n) x = s1, y = s3;
    string res(3 * n, c);
    int i = 0, j = 0, cur = 0;
    for (; i < 2 * n && j < 2 * n;) {
      if (x[i] == y[j]) {
        res[cur++] = x[i], i++, j++;
      } else {
        if (x[i] != c) {
          res[cur++] = x[i++];
        } else {
          res[cur++] = y[j++];
        }
      }
    }
    while (i < 2 * n) res[cur++] = x[i++];
    while (j < 2 * n) res[cur++] = y[j++];
    cout << res << '\n';
  }
}