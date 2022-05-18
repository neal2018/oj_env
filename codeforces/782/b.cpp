#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n, k;
    string s;
    cin >> n >> k >> s;
    vector<ll> cnt(n);
    if (k & 1) {
      for (auto& c : s) c = c ^ '0' ^ '1';
    }

    for (int i = 0, pre = -1; i < n; i++) {
      if (s[i] == '0') {
        if (pre == -1) {
          pre = i;
        } else if (k >= 2) {
          s[i] = '1', s[pre] = '1';
          cnt[i]++, cnt[pre]++;
          pre = -1, k -= 2;
        }
      }
    }
    if (k >= 2) {
      for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
          s[i] = '1', k -= 2, cnt[i]++;
          s[n - 1] = s[n - 1] ^ '0' ^ '1', cnt[n - 1]++;
          break;
        }
      }
    }
    if (k & 1) {
      for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
          s[i] = '1', k--, cnt[i]++;
          break;
        }
      }
      if (k & 1) {
        s[n - 1] = '0';
        k--, cnt[n - 1]++;
      }
    }
    cnt[0] += k;
    cout << s << "\n";
    for (auto& x : cnt) cout << x << " ";
    cout << "\n";
  }
}
